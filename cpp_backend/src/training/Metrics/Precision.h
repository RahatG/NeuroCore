#ifndef PRECISION_H
#define PRECISION_H

#include "Metric.h"

class Precision : public Metric {
public:
    float compute(const std::vector<float>& predictions, const std::vector<float>& targets) override;
};

#endif // PRECISION_H
