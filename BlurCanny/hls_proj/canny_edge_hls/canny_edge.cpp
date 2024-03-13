#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include <hls_math.h>
#include <ap_fixed.h>

#define HEIGHT 2048
#define WIDTH 2048
#define HEIGHT_AFTER_CONV HEIGHT - 2
#define WIDTH_AFTER_CONV WIDTH - 2
#define SOBEL_KERNEL_SIZE 3
#define PI 3.1415

typedef float image_t[HEIGHT][WIDTH];
typedef float image_t_after_conv[HEIGHT_AFTER_CONV][WIDTH_AFTER_CONV];
typedef float result_t[HEIGHT_AFTER_CONV][WIDTH_AFTER_CONV];
typedef float kernel_t[SOBEL_KERNEL_SIZE][SOBEL_KERNEL_SIZE];
typedef ap_axis<32,1,1,1> stream_type;

// Sobel Kernel for Gx and Gy
const float Gx[SOBEL_KERNEL_SIZE][SOBEL_KERNEL_SIZE] = {
    {-1, 0, 1},
    {-2, 0, 2},
    {-1, 0, 1}
};

const float Gy[SOBEL_KERNEL_SIZE][SOBEL_KERNEL_SIZE] = {
    {-1, -2, -1},
    {0, 0, 0},
    {1, 2, 1}
};

void convolve2d(image_t &image, const kernel_t &kernel, image_t_after_conv &new_image) {
    float sum;
    int new_height = HEIGHT - SOBEL_KERNEL_SIZE + 1;
    int new_width = WIDTH - SOBEL_KERNEL_SIZE + 1;

    for (int i = 0; i < new_height; i++) {
        for (int j = 0; j < new_width; j++) {
            sum = 0.0;
            for (int ki = 0; ki < SOBEL_KERNEL_SIZE; ki++) {
                for (int kj = 0; kj < SOBEL_KERNEL_SIZE; kj++) {
                    sum += image[i + ki][j + kj] * kernel[ki][kj];
                }
            }
            new_image[i][j] = sum;
        }
    }
}

// Function to perform Sobel filtering
void sobel_filter(image_t_after_conv &Ix, image_t_after_conv &Iy, image_t_after_conv &gradient_magnitude, image_t_after_conv &gradient_direction) {
    for (int i = 0; i < HEIGHT_AFTER_CONV; i++) {
        for (int j = 0; j < WIDTH_AFTER_CONV; j++) {
            // Compute gradient magnitude
            gradient_magnitude[i][j] = hls::sqrt(Ix[i][j] * Ix[i][j] + Iy[i][j] * Iy[i][j]);

            // Compute gradient direction
            gradient_direction[i][j] = hls::atan2(Iy[i][j], Ix[i][j]);
        }
    }
}

// Function to perform non-maximum suppression
void non_max_suppression(image_t_after_conv &img, image_t_after_conv &D, image_t_after_conv &Z) {
    float angle;
    for (int i = 1; i < HEIGHT_AFTER_CONV - 1; i++) {
        for (int j = 1; j < WIDTH_AFTER_CONV - 1; j++) {
            angle = D[i][j] * 180.0 / PI;
            if (angle < 0) angle += 180;

            float q = 255, r = 255;

            // Angle 0
            if ((0 <= angle && angle < 22.5) || (157.5 <= angle && angle <= 180)) {
                q = img[i][j+1];
                r = img[i][j-1];
            }
            // Angle 45
            else if (22.5 <= angle && angle < 67.5) {
                q = img[i+1][j-1];
                r = img[i-1][j+1];
            }
            // Angle 90
            else if (67.5 <= angle && angle < 112.5) {
                q = img[i+1][j];
                r = img[i-1][j];
            }
            // Angle 135
            else if (112.5 <= angle && angle < 157.5) {
                q = img[i-1][j-1];
                r = img[i+1][j+1];
            }

            if (img[i][j] >= q && img[i][j] >= r) {
                Z[i][j] = img[i][j];
            } else {
                Z[i][j] = 0;
            }
        }
    }
}

// Function to apply thresholding
void threshold(image_t_after_conv &img, result_t &res, float lowThresholdRatio = 0.05, float highThresholdRatio = 0.09) {
    float maxVal = 0;
    for (int i = 0; i < HEIGHT_AFTER_CONV; i++) {
        for (int j = 0; j < WIDTH_AFTER_CONV; j++) {
            if (img[i][j] > maxVal) {
                maxVal = img[i][j];
            }
        }
    }

    float highThreshold = maxVal * highThresholdRatio;
    float lowThreshold = highThreshold * lowThresholdRatio;
    int weak = 25;
    int strong = 255;

    for (int i = 0; i < HEIGHT_AFTER_CONV; i++) {
        for (int j = 0; j < WIDTH_AFTER_CONV; j++) {
            if (img[i][j] >= highThreshold) {
                res[i][j] = strong;
            } else if (img[i][j] >= lowThreshold) {
                res[i][j] = weak;
            } else {
                res[i][j] = 0;
            }
        }
    }
}

// Function to apply hysteresis
void hysteresis(image_t_after_conv &img, int weak, int strong = 255) {
    for (int i = 1; i < HEIGHT_AFTER_CONV - 1; i++) {
        for (int j = 1; j < WIDTH_AFTER_CONV - 1; j++) {
            if (img[i][j] == weak) {
                // Check neighborhood for a strong pixel
                if ((img[i+1][j-1] == strong) || (img[i+1][j] == strong) || (img[i+1][j+1] == strong) ||
                    (img[i][j-1] == strong) || (img[i][j+1] == strong) ||
                    (img[i-1][j-1] == strong) || (img[i-1][j] == strong) || (img[i-1][j+1] == strong)) {
                    img[i][j] = strong;
                } else {
                    img[i][j] = 0;
                }
            }
        }
    }
}

// Top function with port interfaces
void canny_edge_top(hls::stream<stream_type> &input_stream, hls::stream<stream_type> &output_stream) {
    #pragma HLS INTERFACE axis port=input_stream
    #pragma HLS INTERFACE axis port=output_stream
    #pragma HLS INTERFACE s_axilite port=return bundle=CONFIG

    image_t image;
    image_t_after_conv new_image_x;
    image_t_after_conv new_image_y;
    image_t_after_conv gradient_magnitude;
    image_t_after_conv gradient_direction;
    image_t_after_conv non_max_suppressed;
    result_t thresholded;

    // Stream in the image
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            #pragma HLS PIPELINE II=1
            stream_type pixel = input_stream.read();
            image[i][j] = pixel.data;
        }
    }

    // Perform convolution
    convolve2d(image, Gx, new_image_x);
    convolve2d(image, Gy, new_image_y);
    sobel_filter(new_image_x, new_image_y, gradient_magnitude, gradient_direction);
    non_max_suppression(gradient_magnitude, gradient_direction, non_max_suppressed);
    threshold(non_max_suppressed, thresholded);
    hysteresis(thresholded, 25);

    // Stream out the new image
    for (int i = 0; i < HEIGHT_AFTER_CONV; i++) {
        for (int j = 0; j < WIDTH_AFTER_CONV; j++) {
            #pragma HLS PIPELINE II=1
            stream_type pixel;
            pixel.data = thresholded[i][j];
            output_stream.write(pixel);
        }
    }
}