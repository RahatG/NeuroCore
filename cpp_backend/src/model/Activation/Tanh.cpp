#include "Tanh.h"
#include <cmath>

std::vector<float> Tanh::activate(const std::vector<float>& input) {
    std::vector<float> output;
    for (auto val : input) {
        output.push_back(std::tanh(val));
    }
    return output;
}

std::vector<float> Tanh::derivative(const std::vector<float>& input) {
    std::vector<float> derivatives;
    for (auto val : input) {
        float tanh_val = std::tanh(val);
        derivatives.push_back(1.0f - tanh_val * tanh_val);
    }
    return derivatives;
}
