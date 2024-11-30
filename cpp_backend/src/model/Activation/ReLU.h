#ifndef RELU_H
#define RELU_H

#include <vector>

class ReLU {
public:
    std::vector<float> activate(const std::vector<float>& input);
    std::vector<float> derivative(const std::vector<float>& input);
};

#endif // RELU_H
