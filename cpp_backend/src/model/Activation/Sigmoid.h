#ifndef SIGMOID_H
#define SIGMOID_H

#include <vector>

class Sigmoid {
public:
    std::vector<float> activate(const std::vector<float>& input);
    std::vector<float> derivative(const std::vector<float>& input);
};

#endif // SIGMOID_H
