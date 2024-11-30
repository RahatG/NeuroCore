#include "RMSProp.h"
#include <cmath>

RMSProp::RMSProp(float learning_rate, float beta, float epsilon)
        : learning_rate(learning_rate), beta(beta), epsilon(epsilon), t(0) {}

void RMSProp::update(std::vector<float>& weights, const std::vector<float>& grad) {
    t += 1;
    for (size_t i = 0; i < weights.size(); ++i) {
        cache[i] = beta * cache[i] + (1 - beta) * grad[i] * grad[i];
        weights[i] -= learning_rate * grad[i] / (sqrt(cache[i]) + epsilon);
    }
}
