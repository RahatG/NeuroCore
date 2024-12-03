#ifndef RECALL_H
#define RECALL_H

#include "Metric.h"

class Recall : public Metric {
public:
    float compute(const std::vector<float>& predictions, const std::vector<float>& targets) override;
};

#endif // RECALL_H
