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

// Function to perform 2D convolution with line buffering
void convolve2d(hls::stream<stream_type> &input_stream, const kernel_t &kernel, hls::stream<stream_type> &output_stream) {
    float line_buffer[KERNEL_SIZE][WIDTH];
    #pragma HLS ARRAY_PARTITION variable=line_buffer complete dim=1
    
    float window[KERNEL_SIZE][KERNEL_SIZE];
    #pragma HLS ARRAY_PARTITION variable=window complete dim=0

    stream_type pixel;
    float sum;

    for (int i = 0; i < HEIGHT + KERNEL_RADIUS; i++) {
        for (int j = 0; j < WIDTH; j++) {
            #pragma HLS PIPELINE II=1
            
            // Shift up the window
            for(int wi = 0; wi < KERNEL_SIZE-1; wi++) {
                for(int wj = 0; wj < KERNEL_SIZE; wj++) {
                    if(i < HEIGHT) {
                        window[wi][wj] = window[wi+1][wj];
                    }
                }
            }
            
            // Load the new line into the line buffer
            if(i < HEIGHT) {
                pixel = input_stream.read();
                line_buffer[KERNEL_SIZE-1][j] = pixel.data;
            }
            
            // Update the bottom row of the window
            for(int wj = 0; wj < KERNEL_SIZE; wj++) {
                int image_col = j - KERNEL_RADIUS + wj;
                if(image_col >= 0 && image_col < WIDTH) {
                    if(i < HEIGHT) {
                        window[KERNEL_SIZE-1][wj] = line_buffer[KERNEL_SIZE-1][image_col];
                    }
                }
            }
            
            // Perform the convolution
            if(i >= KERNEL_SIZE-1 && j >= KERNEL_RADIUS) {
                sum = 0;
                for(int ki = 0; ki < KERNEL_SIZE; ki++) {
                    for(int kj = 0; kj < KERNEL_SIZE; kj++) {
                        sum += window[ki][kj] * kernel[ki][kj];
                    }
                }
                if(j >= KERNEL_SIZE-1) {
                    pixel.data = sum;
                    output_stream.write(pixel);
                }
            }
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

    // #pragma HLS ARRAY_PARTITION variable=image complete dim=2
    // #pragma HLS ARRAY_PARTITION variable=new_image complete dim=2

    // Stream in the image
    convolve2d(input_stream, gaussian_kernel, output_stream);
}
