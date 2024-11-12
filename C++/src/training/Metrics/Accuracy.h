#ifndef ACCURACY_H
#define ACCURACY_H

#include "Metric.h"

class Accuracy : public Metric {
public:
    float compute(const std::vector<float>& predictions, const std::vector<float>& targets) override;
};

#endif // ACCURACY_H
