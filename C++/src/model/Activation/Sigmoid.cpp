#include "Sigmoid.h"
#include <cmath>

std::vector<float> Sigmoid::activate(const std::vector<float>& input) {
    std::vector<float> output;
    for (auto val : input) {
        output.push_back(1.0f / (1.0f + std::exp(-val)));
    }
    return output;
}

std::vector<float> Sigmoid::derivative(const std::vector<float>& input) {
    std::vector<float> derivatives;
    for (auto val : input) {
        float sigmoid = 1.0f / (1.0f + std::exp(-val));
        derivatives.push_back(sigmoid * (1 - sigmoid));
    }
    return derivatives;
}
