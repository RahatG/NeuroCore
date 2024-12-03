#ifndef CONVOLUTIONLAYER_H
#define CONVOLUTIONLAYER_H

#include <vector>

class ConvolutionLayer {
public:
    ConvolutionLayer(int input_channels, int output_channels, int kernel_size);
    std::vector<float> forward(const std::vector<float>& input);
    std::vector<float> backward(const std::vector<float>& grad_output);
private:
    int input_channels;
    int output_channels;
    int kernel_size;
    std::vector<std::vector<float>> kernels;
    std::vector<float> biases;
    std::vector<float> input;
};

#endif // CONVOLUTIONLAYER_H
