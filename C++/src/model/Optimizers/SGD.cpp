#include "SGD.h"

SGD::SGD(float learning_rate) : lr(learning_rate) {}

void SGD::update(std::vector<std::vector<float>>& weights, std::vector<float>& biases) {
    for(auto &layer_weights : weights) {
        for(auto &w : layer_weights) {
            // Placeholder gradient; replace with actual gradient
            float grad = 0.01f;
            w -= lr * grad;
        }
    }
    for(auto &b : biases) {
        // Placeholder gradient; replace with actual gradient
        float grad = 0.01f;
        b -= lr * grad;
    }
}
