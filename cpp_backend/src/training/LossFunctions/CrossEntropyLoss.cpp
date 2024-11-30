#include "CrossEntropyLoss.h"
#include <cmath>

float CrossEntropyLoss::compute_loss(const std::vector<float>& predictions, const std::vector<float>& targets) {
    float loss = 0.0f;
    for(size_t i = 0; i < predictions.size(); ++i) {
        loss -= targets[i] * std::log(predictions[i] + 1e-15f);
    }
    return loss;
}

std::vector<float> CrossEntropyLoss::compute_gradient(const std::vector<float>& predictions, const std::vector<float>& targets) {
    std::vector<float> grad(predictions.size(), 0.0f);
    for(size_t i = 0; i < predictions.size(); ++i) {
        grad[i] = -targets[i] / (predictions[i] + 1e-15f);
    }
    return grad;
}
