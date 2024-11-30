#ifndef MEANSQUAREDLOSS_H
#define MEANSQUAREDLOSS_H

#include "LossFunction.h"

class MeanSquaredLoss : public LossFunction {
public:
    float compute_loss(const std::vector<float>& predictions, const std::vector<float>& targets) override;
    std::vector<float> compute_gradient(const std::vector<float>& predictions, const std::vector<float>& targets) override;
};

#endif // MEANSQUAREDLOSS_H
