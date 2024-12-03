#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <vector>

class Optimizer {
public:
    virtual ~Optimizer() {}
    virtual void update(
        std::vector<std::vector<float>>& weights,
        const std::vector<std::vector<float>>& weight_grads,
        std::vector<float>& biases,
        const std::vector<float>& bias_grads
    ) = 0;
};

#endif // OPTIMIZER_H
