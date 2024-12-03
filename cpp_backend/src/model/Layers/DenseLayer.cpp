#include "DenseLayer.h"
#include <cstdlib>
#include <algorithm>
#include <cmath>

// Constructor with Xavier Initialization
DenseLayer::DenseLayer(int input_sz, int output_sz)
        : input_size(input_sz), output_size(output_sz),
          weights(output_sz, std::vector<float>(input_sz)),
          biases(output_sz, 0.0f),
          weight_gradients(output_sz, std::vector<float>(input_sz, 0.0f)),
          bias_gradients(output_sz, 0.0f) {
    // Xavier Initialization
    float limit = std::sqrt(6.0f / (input_size + output_size));
    for(auto &row : weights) {
        for(auto &w : row) {
            w = ((static_cast<float>(rand()) / RAND_MAX) * 2 * limit) - limit;
        }
    }
}

// Forward Pass
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

// Backward Pass
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

// Const Accessors
const std::vector<std::vector<float>>& DenseLayer::get_weights() const {
    return weights;
}

const std::vector<float>& DenseLayer::get_biases() const {
    return biases;
}

const std::vector<std::vector<float>>& DenseLayer::get_weight_gradients() const {
    return weight_gradients;
}

const std::vector<float>& DenseLayer::get_bias_gradients() const {
    return bias_gradients;
}

// Non-const Accessors
std::vector<std::vector<float>>& DenseLayer::get_weights() {
    return weights;
}

std::vector<float>& DenseLayer::get_biases() {
    return biases;
}

std::vector<std::vector<float>>& DenseLayer::get_weight_gradients() {
    return weight_gradients;
}

std::vector<float>& DenseLayer::get_bias_gradients() {
    return bias_gradients;
}

// Reset Gradients
void DenseLayer::reset_gradients() {
    for(auto& wg : weight_gradients) {
        std::fill(wg.begin(), wg.end(), 0.0f);
    }
    std::fill(bias_gradients.begin(), bias_gradients.end(), 0.0f);
}
