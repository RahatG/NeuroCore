#ifndef ADAM_H
#define ADAM_H

#include <vector>
#include "Optimizer.h"

class Adam : public Optimizer {
public:
    Adam(float learning_rate, float beta1, float beta2, float epsilon);
    void update(std::vector<float>& weights, const std::vector<float>& grad) override;

private:
    float learning_rate;
    float beta1;
    float beta2;
    float epsilon;
    int t;
    std::vector<float> m;
    std::vector<float> v;
};

#endif // ADAM_H
