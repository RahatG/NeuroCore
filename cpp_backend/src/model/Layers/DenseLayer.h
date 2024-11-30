#ifndef DENSELAYER_H
#define DENSELAYER_H

#include <vector>

class DenseLayer {
public:
    DenseLayer(int input_size, int output_size);
    std::vector<float> forward(const std::vector<float>& input);
    std::vector<float> backward(const std::vector<float>& grad_output);

    // Accessors for weights and biases
    std::vector<std::vector<float>>& get_weights();
    std::vector<float>& get_biases();

    // Accessors for gradients
    std::vector<std::vector<float>> get_weight_gradients() const;
    std::vector<float> get_bias_gradients() const;

private:
    int input_size;
    int output_size;
    std::vector<std::vector<float>> weights;
    std::vector<float> biases;
    std::vector<float> input;

    // Gradients
    std::vector<std::vector<float>> weight_gradients;
    std::vector<float> bias_gradients;
};

#endif // DENSELAYER_H
