#ifndef METRIC_H
#define METRIC_H

#include <vector>

class Metric {
public:
    virtual ~Metric() {}
    virtual float compute(const std::vector<float>& predictions, const std::vector<float>& targets) = 0;
};

#endif // METRIC_H
