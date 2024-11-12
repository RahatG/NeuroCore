#include "SGD.h"

SGD::SGD(float learning_rate) : lr(learning_rate) {}

void SGD::update(std::vector<std::vector<float>>& weights, std::vector<float>& biases) {
    for(auto &layer_weights : weights) {
        for(auto &w : layer_weights) {
            w -= lr * w; // Placeholder gradient
        }
    }
    for(auto &b : biases) {
        b -= lr * b; // Placeholder gradient
    }
}
