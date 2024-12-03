#include "Accuracy.h"
#include <algorithm>

Accuracy::~Accuracy() {
    // Destructor definition (even if empty)
}

float Accuracy::compute(const std::vector<float>& predictions, const std::vector<float>& targets) {
    auto pred_it = std::max_element(predictions.begin(), predictions.end());
    auto target_it = std::max_element(targets.begin(), targets.end());
    int pred_class = std::distance(predictions.begin(), pred_it);
    int target_class = std::distance(targets.begin(), target_it);
    return pred_class == target_class ? 1.0f : 0.0f;
}
