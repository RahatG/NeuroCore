#include "Accuracy.h"

float Accuracy::compute(const std::vector<float>& predictions, const std::vector<float>& targets) {
    int correct = 0;
    for(size_t i = 0; i < predictions.size(); ++i) {
        if((predictions[i] > 0.5f) == (targets[i] > 0.5f)) {
            correct++;
        }
    }
    return static_cast<float>(correct) / predictions.size();
}
