#ifndef RMSPROP_H
#define RMSPROP_H

#include <vector>
#include "Optimizer.h"

class RMSProp : public Optimizer {
public:
    RMSProp(float learning_rate, float beta, float epsilon);
    void update(std::vector<float>& weights, const std::vector<float>& grad) override;

private:
    float learning_rate;
    float beta;
    float epsilon;
    int t;
    std::vector<float> cache;
};

#endif // RMSPROP_H
