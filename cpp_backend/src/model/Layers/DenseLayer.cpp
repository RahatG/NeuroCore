#include "DenseLayer.h"
#include <cstdlib>

DenseLayer::DenseLayer(int input_sz, int output_sz)
        : input_size(input_sz), output_size(output_sz),
          weights(output_sz, std::vector<float>(input_sz)),
          biases(output_sz, 0.0f),
          weight_gradients(output_sz, std::vector<float>(input_sz, 0.0f)),
          bias_gradients(output_sz, 0.0f) {
    // Initialize weights and biases
    for(auto &row : weights) {
        for(auto &w : row) {
            w = static_cast<float>(rand()) / RAND_MAX;
        }
    }
}

std::vector<float> DenseLayer::forward(const std::vector<float>& input_data) {
    input = input_data;
    std::vector<float> output(output_size, 0.0f);
    for(int i = 0; i < output_size; ++i) {
        for(int j = 0; j < input_size; ++j) {
            output[i] += weights[i][j] * input[j];
        }
        output[i] += biases[i];
    }
    return output;
}

std::vector<float> DenseLayer::backward(const std::vector<float>& grad_output) {
    // Compute gradients w.r.t weights and biases
    for(int i = 0; i < output_size; ++i) {
        for(int j = 0; j < input_size; ++j) {
            weight_gradients[i][j] += grad_output[i] * input[j];
        }
        bias_gradients[i] += grad_output[i];
    }

    // Compute gradient w.r.t input to propagate to previous layers
    std::vector<float> grad_input(input_size, 0.0f);
    for(int j = 0; j < input_size; ++j) {
        for(int i = 0; i < output_size; ++i) {
            grad_input[j] += weights[i][j] * grad_output[i];
        }
    }
    return grad_input;
}

std::vector<std::vector<float>>& DenseLayer::get_weights() {
    return weights;
}

std::vector<float>& DenseLayer::get_biases() {
    return biases;
}

std::vector<std::vector<float>> DenseLayer::get_weight_gradients() const {
    return weight_gradients;
}

std::vector<float> DenseLayer::get_bias_gradients() const {
    return bias_gradients;
}
