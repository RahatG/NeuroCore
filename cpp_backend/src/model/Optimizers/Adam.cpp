#include "Adam.h"
#include <cmath>

Adam::Adam(float lr, float b1, float b2, float eps)
        : learning_rate(lr), beta1(b1), beta2(b2), epsilon(eps), t(0) {}

void Adam::update(
    std::vector<std::vector<float>>& weights,
    const std::vector<std::vector<float>>& weight_grads,
    std::vector<float>& biases,
    const std::vector<float>& bias_grads
) {
    t += 1;

    // Initialize moment vectors if first update
    if (m_weights.empty()) {
        m_weights.resize(weights.size());
        v_weights.resize(weights.size());
        for (size_t i = 0; i < weights.size(); ++i) {
            m_weights[i].resize(weights[i].size(), 0.0f);
            v_weights[i].resize(weights[i].size(), 0.0f);
        }
    }

    if (m_biases.empty()) {
        m_biases.resize(biases.size(), 0.0f);
        v_biases.resize(biases.size(), 0.0f);
    }

    // Update weights
    for (size_t i = 0; i < weights.size(); ++i) {
        for (size_t j = 0; j < weights[i].size(); ++j) {
            m_weights[i][j] = beta1 * m_weights[i][j] + (1 - beta1) * weight_grads[i][j];
            v_weights[i][j] = beta2 * v_weights[i][j] + (1 - beta2) * weight_grads[i][j] * weight_grads[i][j];
            float m_hat = m_weights[i][j] / (1 - std::pow(beta1, t));
            float v_hat = v_weights[i][j] / (1 - std::pow(beta2, t));
            weights[i][j] -= learning_rate * m_hat / (std::sqrt(v_hat) + epsilon);
        }
    }

    // Update biases
    for (size_t i = 0; i < biases.size(); ++i) {
        m_biases[i] = beta1 * m_biases[i] + (1 - beta1) * bias_grads[i];
        v_biases[i] = beta2 * v_biases[i] + (1 - beta2) * bias_grads[i] * bias_grads[i];
        float m_hat = m_biases[i] / (1 - std::pow(beta1, t));
        float v_hat = v_biases[i] / (1 - std::pow(beta2, t));
        biases[i] -= learning_rate * m_hat / (std::sqrt(v_hat) + epsilon);
    }
}
