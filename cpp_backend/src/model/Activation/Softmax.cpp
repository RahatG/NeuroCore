// Softmax.cpp
#include "Softmax.h"
#include <cmath>
#include <algorithm>

namespace Activation {

    std::vector<float> Softmax::derivative(const std::vector<float>& output) const {
        // Implementation of the derivative
        std::vector<float> derivative(output.size(), 0.0f);
        for (size_t i = 0; i < output.size(); ++i) {
            derivative[i] = output[i] * (1.0f - output[i]);
        }
        return derivative;
    }

    std::vector<float> Softmax::activate(const std::vector<float>& input) {
        std::vector<float> exps;
        float max_val = *std::max_element(input.begin(), input.end());
        float sum = 0.0f;
        for (auto val : input) {
            float e = std::exp(val - max_val);
            exps.push_back(e);
            sum += e;
        }
        std::vector<float> output;
        for (auto e : exps) {
            output.push_back(e / sum);
        }
        return output;
    }
} // namespace Activation
