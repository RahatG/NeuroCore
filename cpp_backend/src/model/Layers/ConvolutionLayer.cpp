#include "ConvolutionLayer.h"
#include <cstdlib>

ConvolutionLayer::ConvolutionLayer(int in_ch, int out_ch, int k_size)
    : input_channels(in_ch), output_channels(out_ch), kernel_size(k_size),
      kernels(out_ch, std::vector<float>(in_ch * kernel_size * kernel_size)),
      biases(out_ch, 0.0f) {
    // Initialize kernels and biases
    for(auto &kernel : kernels) {
        for(auto &w : kernel) {
            w = static_cast<float>(rand()) / RAND_MAX;
        }
    }
}

std::vector<float> ConvolutionLayer::forward(const std::vector<float>& input_data) {
    input = input_data;
    // Simple convolution operation (placeholder)
    std::vector<float> output(output_channels, 0.0f);
    for(int o = 0; o < output_channels; ++o) {
        for(int i = 0; i < input_channels * kernel_size * kernel_size; ++i) {
            output[o] += kernels[o][i] * input_data[i];
        }
        output[o] += biases[o];
    }
    return output;
}

std::vector<float> ConvolutionLayer::backward(const std::vector<float>& grad_output) {
    std::vector<float> grad_input(input_channels * kernel_size * kernel_size, 0.0f);
    // Simple backward operation (placeholder)
    for(int o = 0; o < output_channels; ++o) {
        for(int i = 0; i < input_channels * kernel_size * kernel_size; ++i) {
            grad_input[i] += kernels[o][i] * grad_output[o];
            // Update kernels and biases here if implementing training
        }
    }
    return grad_input;
}
