#include "Precision.h"

float Precision::compute(const std::vector<float>& predictions, const std::vector<float>& targets) {
    int true_positive = 0;
    int predicted_positive = 0;
    for(size_t i = 0; i < predictions.size(); ++i) {
        if(predictions[i] > 0.5f) {
            predicted_positive++;
            if(targets[i] > 0.5f) {
                true_positive++;
            }
        }
    }
    return predicted_positive > 0 ? static_cast<float>(true_positive) / predicted_positive : 0.0f;
}
