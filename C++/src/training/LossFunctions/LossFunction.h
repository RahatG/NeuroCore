#ifndef LOSSFUNCTION_H
#define LOSSFUNCTION_H

#include <vector>

class LossFunction {
public:
    virtual float compute_loss(const std::vector<float>& predictions, const std::vector<float>& targets) = 0;
    virtual std::vector<float> compute_gradient(const std::vector<float>& predictions, const std::vector<float>& targets) = 0;
};

#endif // LOSSFUNCTION_H
