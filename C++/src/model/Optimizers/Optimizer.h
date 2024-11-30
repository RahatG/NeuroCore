#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <vector>

class Optimizer {
public:
    virtual ~Optimizer() {}
    virtual void update(std::vector<std::vector<float>>& weights, std::vector<float>& biases) = 0;
};

#endif // OPTIMIZER_H
