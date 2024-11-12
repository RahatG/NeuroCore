#ifndef SGD_H
#define SGD_H

#include "Optimizer.h"

class SGD : public Optimizer {
public:
    SGD(float learning_rate);
    void update(std::vector<std::vector<float>>& weights, std::vector<float>& biases) override;
private:
    float lr;
};

#endif // SGD_H
