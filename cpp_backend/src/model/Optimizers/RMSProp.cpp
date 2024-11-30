#include "RMSProp.h"
#include <cmath>

RMSProp::RMSProp(float learning_rate, float beta, float epsilon)
        : learning_rate(learning_rate), beta(beta), epsilon(epsilon), t(0), cache( /* initialize size appropriately */ ) {}

void RMSProp::update(
        std::vector<std::vector<float>>& weights,
        const std::vector<std::vector<float>>& weight_grads,
        std::vector<float>& biases,
        const std::vector<float>& bias_grads
) {
    t += 1;
    for (size_t i = 0; i < weights.size(); ++i) {
        for (size_t j = 0; j < weights[i].size(); ++j) {
            cache[j] = beta * cache[j] + (1 - beta) * weight_grads[i][j] * weight_grads[i][j];
            weights[i][j] -= learning_rate * weight_grads[i][j] / (std::sqrt(cache[j]) + epsilon);
        }
    }
    for (size_t i = 0; i < biases.size(); ++i) {
        biases[i] -= learning_rate * bias_grads[i];
    }
}
