#include "Softmax.h"
#include <cmath>

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
