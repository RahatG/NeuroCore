#include "ReLU.h"

std::vector<float> ReLU::activate(const std::vector<float>& input) {
    std::vector<float> output;
    for (auto val : input) {
        output.push_back(val > 0 ? val : 0);
    }
    return output;
}

std::vector<float> ReLU::derivative(const std::vector<float>& input) {
    std::vector<float> derivatives;
    for (auto val : input) {
        derivatives.push_back(val > 0 ? 1.0f : 0.0f);
    }
    return derivatives;
}
