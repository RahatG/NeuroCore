#ifndef TANH_H
#define TANH_H

#include <vector>

class Tanh {
public:
    std::vector<float> activate(const std::vector<float>& input);
    std::vector<float> derivative(const std::vector<float>& input);
};

#endif // TANH_H
