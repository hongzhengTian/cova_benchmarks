#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include <hls_math.h>
#include <ap_fixed.h>

#define HEIGHT 2048
#define WIDTH 2048
#define HEIGHT_AFTER_CONV HEIGHT - 10
#define WIDTH_AFTER_CONV WIDTH - 10
#define KERNEL_SIZE 11
#define KERNEL_RADIUS KERNEL_SIZE / 2
#define SIGMA 1

typedef float image_t[HEIGHT][WIDTH];
typedef float image_t_after_conv[HEIGHT_AFTER_CONV][WIDTH_AFTER_CONV];
typedef float kernel_t[KERNEL_SIZE][KERNEL_SIZE];
typedef ap_axis<32,1,1,1> stream_type;

// Hardcoded 11x11 Gaussian kernel, replace the placeholder with the actual kernel
const float gaussian_kernel[KERNEL_SIZE][KERNEL_SIZE] = {
    {0.001491, 0.002244, 0.003085, 0.003872, 0.004438, 0.004644, 0.004438, 0.003872, 0.003085, 0.002244, 0.001491},
    {0.002244, 0.003379, 0.004644, 0.005829, 0.006681, 0.006992, 0.006681, 0.005829, 0.004644, 0.003379, 0.002244},
    {0.003085, 0.004644, 0.006384, 0.008013, 0.009184, 0.009611, 0.009184, 0.008013, 0.006384, 0.004644, 0.003085},
    {0.003872, 0.005829, 0.008013, 0.010058, 0.011527, 0.012063, 0.011527, 0.010058, 0.008013, 0.005829, 0.003872},
    {0.004438, 0.006681, 0.009184, 0.011527, 0.013211, 0.013826, 0.013211, 0.011527, 0.009184, 0.006681, 0.004438},
    {0.004644, 0.006992, 0.009611, 0.012063, 0.013826, 0.014469, 0.013826, 0.012063, 0.009611, 0.006992, 0.004644},
    {0.004438, 0.006681, 0.009184, 0.011527, 0.013211, 0.013826, 0.013211, 0.011527, 0.009184, 0.006681, 0.004438},
    {0.003872, 0.005829, 0.008013, 0.010058, 0.011527, 0.012063, 0.011527, 0.010058, 0.008013, 0.005829, 0.003872},
    {0.003085, 0.004644, 0.006384, 0.008013, 0.009184, 0.009611, 0.009184, 0.008013, 0.006384, 0.004644, 0.003085},
    {0.002244, 0.003379, 0.004644, 0.005829, 0.006681, 0.006992, 0.006681, 0.005829, 0.004644, 0.003379, 0.002244},
    {0.001491, 0.002244, 0.003085, 0.003872, 0.004438, 0.004644, 0.004438, 0.003872, 0.003085, 0.002244, 0.001491}
};

// Function to perform 2D convolution, output size is reduced based on the kernel size
void convolve2d(image_t &image, const kernel_t &kernel, image_t_after_conv &new_image) {
    float sum;
    int new_height = HEIGHT - KERNEL_SIZE + 1;
    int new_width = WIDTH - KERNEL_SIZE + 1;

    for (int i = 0; i < new_height; i++) {
        for (int j = 0; j < new_width; j++) {
            sum = 0.0;
            for (int ki = 0; ki < KERNEL_SIZE; ki++) {
                for (int kj = 0; kj < KERNEL_SIZE; kj++) {
                    sum += image[i + ki][j + kj] * kernel[ki][kj];
                }
            }
            new_image[i][j] = sum;
        }
    }
}

// Top function with port interfaces
void gaussian_blur_top(hls::stream<stream_type> &input_stream, hls::stream<stream_type> &output_stream) {
    #pragma HLS INTERFACE axis port=input_stream
    #pragma HLS INTERFACE axis port=output_stream
    #pragma HLS INTERFACE s_axilite port=return bundle=CONFIG


    // #pragma HLS DATAFLOW
    #pragma HLS ARRAY_PARTITION variable=gaussian_kernel complete dim=2

    image_t image;
    image_t_after_conv new_image;

    // #pragma HLS ARRAY_PARTITION variable=image complete dim=2
    // #pragma HLS ARRAY_PARTITION variable=new_image complete dim=2

    // Stream in the image
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            #pragma HLS PIPELINE II=1
            stream_type pixel = input_stream.read();
            image[i][j] = pixel.data;
        }
    }

    // Perform convolution
    convolve2d(image, gaussian_kernel, new_image);

    // Stream out the new image
    for (int i = 0; i < HEIGHT - KERNEL_SIZE + 1; i++) {
        for (int j = 0; j < WIDTH - KERNEL_SIZE + 1; j++) {
            #pragma HLS PIPELINE II=1
            stream_type pixel;
            pixel.data = new_image[i][j];
            output_stream.write(pixel);
        }
    }
}
