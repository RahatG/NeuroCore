#ifndef ACCURACY_H
#define ACCURACY_H

#include "Metric.h"

class Accuracy : public Metric {
public:
    Accuracy() = default;
    virtual ~Accuracy() override;  // Explicit destructor declaration

    float compute(const std::vector<float>& predictions, const std::vector<float>& targets) override;
};

#endif // ACCURACY_H
