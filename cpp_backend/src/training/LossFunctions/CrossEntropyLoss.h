// src/training/LossFunctions/CrossEntropyLoss.h

#ifndef CROSSENTROPYLOSS_H
#define CROSSENTROPYLOSS_H

#include "LossFunction.h"
#include <vector>

class CrossEntropyLoss : public LossFunction {
public:
    CrossEntropyLoss() = default;
    virtual ~CrossEntropyLoss() override;  // Explicit destructor declaration

    float compute_loss(const std::vector<float>& predictions, const std::vector<float>& targets) override;
    std::vector<float> compute_gradient(const std::vector<float>& predictions, const std::vector<float>& targets) override;
};

#endif // CROSSENTROPYLOSS_H
