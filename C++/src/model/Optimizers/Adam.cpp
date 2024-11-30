#include "Adam.h"
#include <cmath>

Adam::Adam(float learning_rate, float beta1, float beta2, float epsilon)
        : learning_rate(learning_rate), beta1(beta1), beta2(beta2), epsilon(epsilon), t(0) {}

void Adam::update(std::vector<std::vector<float>>& weights, std::vector<float>& biases) {
    t += 1;
    for (size_t i = 0; i < weights.size(); ++i) {
        for (size_t j = 0; j < weights[i].size(); ++j) {
            // Initialize m and v if first update
            if (m.size() <= i) {
                m.emplace_back(std::vector<float>(weights[i].size(), 0.0f));
                v.emplace_back(std::vector<float>(weights[i].size(), 0.0f));
            }

            m[i][j] = beta1 * m[i][j] + (1 - beta1) * weights[i][j];
            v[i][j] = beta2 * v[i][j] + (1 - beta2) * weights[i][j] * weights[i][j];

            float m_hat = m[i][j] / (1 - std::pow(beta1, t));
            float v_hat = v[i][j] / (1 - std::pow(beta2, t));

            weights[i][j] -= learning_rate * m_hat / (std::sqrt(v_hat) + epsilon);
        }
    }

    // Similarly update biases if needed
}
