#ifndef SOFTMAX_H
#define SOFTMAX_H

#include <vector>

class Softmax {
public:
    std::vector<float> activate(const std::vector<float>& input);
    // Derivative not typically used with cross-entropy loss
};

#endif // SOFTMAX_H
