#include "SGD.h"

SGD::SGD(float learning_rate) : lr(learning_rate) {}

void SGD::update(std::vector<std::vector<float>>& weights,
                const std::vector<std::vector<float>>& weight_grads,
                std::vector<float>& biases,
                const std::vector<float>& bias_grads) {
    for(size_t i = 0; i < weights.size(); ++i) {
        for(size_t j = 0; j < weights[i].size(); ++j) {
            weights[i][j] -= lr * weight_grads[i][j];
        }
    }
    for(size_t i = 0; i < biases.size(); ++i) {
        biases[i] -= lr * bias_grads[i];
    }
}
