// src/training/LossFunctions/CrossEntropyLoss.cpp

#include "CrossEntropyLoss.h"
#include <cmath>
#include <algorithm>

CrossEntropyLoss::~CrossEntropyLoss() {
    // Destructor definition (even if empty)
}

float CrossEntropyLoss::compute_loss(const std::vector<float>& predictions, const std::vector<float>& targets) {
    float loss = 0.0f;
    for(size_t i = 0; i < predictions.size(); ++i) {
        float pred = std::max(predictions[i], 1e-15f);
        loss -= targets[i] * std::log(pred);
    }
    return loss;
}

std::vector<float> CrossEntropyLoss::compute_gradient(const std::vector<float>& predictions, const std::vector<float>& targets) {
    std::vector<float> grad(predictions.size(), 0.0f);
    for(size_t i = 0; i < predictions.size(); ++i) {
        float pred = std::max(predictions[i], 1e-15f);
        grad[i] = -targets[i] / pred;
    }
    return grad;
}
