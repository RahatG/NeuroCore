#ifndef RMSPROP_H
#define RMSPROP_H

#include <vector>
#include "Optimizer.h"

class RMSProp : public Optimizer {
public:
    RMSProp(float learning_rate, float beta, float epsilon);
    void update(
            std::vector<std::vector<float>>& weights,
            const std::vector<std::vector<float>>& weight_grads,
            std::vector<float>& biases,
            const std::vector<float>& bias_grads
    ) override; // Added 'override'

private:
    float learning_rate;
    float beta;
    float epsilon;
    int t;
    std::vector<float> cache;
};

#endif // RMSPROP_H
