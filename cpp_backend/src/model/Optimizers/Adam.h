#ifndef ADAM_H
#define ADAM_H

#include "Optimizer.h"
#include <vector>

class Adam : public Optimizer {
public:
    Adam(float learning_rate, float beta1, float beta2, float epsilon);
    void update(
        std::vector<std::vector<float>>& weights,
        const std::vector<std::vector<float>>& weight_grads,
        std::vector<float>& biases,
        const std::vector<float>& bias_grads
    ) override;

private:
    float learning_rate;
    float beta1;
    float beta2;
    float epsilon;
    int t;
    std::vector<std::vector<float>> m_weights;
    std::vector<std::vector<float>> v_weights;
    std::vector<float> m_biases;
    std::vector<float> v_biases;
};

#endif // ADAM_H
