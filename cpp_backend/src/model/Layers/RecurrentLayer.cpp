#include "RecurrentLayer.h"
#include <cstdlib>
#include <valarray>
#include <cstddef> // Add this line

RecurrentLayer::RecurrentLayer(int in_size, int hid_size)
        : input_size(in_size), hidden_size(hid_size),
          weights_input(hid_size, std::vector<float>(in_size)),
          weights_hidden(hid_size, std::vector<float>(hid_size)),
          biases(hid_size, 0.0f),
          hidden_state(hid_size, 0.0f) {
    // Initialize weights and biases
    for (auto &row : weights_input) {
        for (auto &w : row) {
            w = static_cast<float>(rand()) / RAND_MAX;
        }
    }
    for (auto &row : weights_hidden) {
        for (auto &w : row) {
            w = static_cast<float>(rand()) / RAND_MAX;
        }
    }
}

std::vector<float> RecurrentLayer::forward(const std::vector<float>& input_data) {
    std::vector<float> output(hidden_size, 0.0f);
    for (int h = 0; h < hidden_size; ++h) {
        for (int i = 0; i < input_size; ++i) {
            output[h] += weights_input[h][i] * input_data[i];
        }
        for (int h_prev = 0; h_prev < hidden_size; ++h_prev) {
            output[h] += weights_hidden[h][h_prev] * hidden_state[h_prev];
        }
        output[h] += biases[h];
        // Apply activation (e.g., tanh) here if needed
        hidden_state[h] = std::tanh(output[h]);
    }
    return hidden_state;
}

std::vector<float> RecurrentLayer::backward(const std::vector<float>& grad_output) {
    (void)grad_output; // Mark as intentionally unused

    // Placeholder: Implement backward logic
    return std::vector<float>();
}