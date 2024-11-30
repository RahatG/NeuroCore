#include <cstddef> // Add this line
#include "Recall.h"

float Recall::compute(const std::vector<float>& predictions, const std::vector<float>& targets) {
    int true_positive = 0;
    int actual_positive = 0;
    for (std::size_t i = 0; i < predictions.size(); ++i) {
        if (targets[i] > 0.5f) {
            actual_positive++;
            if (predictions[i] > 0.5f) {
                true_positive++;
            }
        }
    }
    return actual_positive > 0 ? static_cast<float>(true_positive) / actual_positive : 0.0f;
}
