#ifndef DENSELAYER_H
#define DENSELAYER_H

#include <vector>

class DenseLayer {
public:
    DenseLayer(int input_size, int output_size);
    std::vector<float> forward(const std::vector<float>& input);
    std::vector<float> backward(const std::vector<float>& grad_output);
private:
    int input_size;
    int output_size;
    std::vector<std::vector<float>> weights;
    std::vector<float> biases;
    std::vector<float> input;
};

#endif // DENSELAYER_H
