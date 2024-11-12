#include "Adam.h"
#include <cmath>

Adam::Adam(float learning_rate, float beta1, float beta2, float epsilon)
        : learning_rate(learning_rate), beta1(beta1), beta2(beta2), epsilon(epsilon), t(0) {}

void Adam::update(std::vector<float>& weights, const std::vector<float>& grad) {
    t += 1;
    for (size_t i = 0; i < weights.size(); ++i) {
        m[i] = beta1 * m[i] + (1 - beta1) * grad[i];
        v[i] = beta2 * v[i] + (1 - beta2) * grad[i] * grad[i];
        float m_hat = m[i] / (1 - pow(beta1, t));
        float v_hat = v[i] / (1 - pow(beta2, t));
        weights[i] -= learning_rate * m_hat / (sqrt(v_hat) + epsilon);
    }
}
