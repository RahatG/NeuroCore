#ifndef CROSSENTROPYLOSS_H
#define CROSSENTROPYLOSS_H

#include "LossFunction.h"

class CrossEntropyLoss : public LossFunction {
public:
    float compute_loss(const std::vector<float>& predictions, const std::vector<float>& targets) override;
    std::vector<float> compute_gradient(const std::vector<float>& predictions, const std::vector<float>& targets) override;
};

#endif // CROSSENTROPYLOSS_H
