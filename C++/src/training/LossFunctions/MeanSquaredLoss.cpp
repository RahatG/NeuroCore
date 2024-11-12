#include "MeanSquaredLoss.h"

float MeanSquaredLoss::compute_loss(const std::vector<float>& predictions, const std::vector<float>& targets) {
    float loss = 0.0f;
    for(size_t i = 0; i < predictions.size(); ++i) {
        float diff = predictions[i] - targets[i];
        loss += diff * diff;
    }
    return loss / predictions.size();
}

std::vector<float> MeanSquaredLoss::compute_gradient(const std::vector<float>& predictions, const std::vector<float>& targets) {
    std::vector<float> grad(predictions.size(), 0.0f);
    for(size_t i = 0; i < predictions.size(); ++i) {
        grad[i] = 2.0f * (predictions[i] - targets[i]) / predictions.size();
    }
    return grad;
}
