#ifndef OPTIMISER_H
#define OPTIMISER_H

#include "Optimizer.h"
#include <vector>

class Optimiser : public Optimizer {
public:
    Optimiser(const std::string& type, float lr);
    void update(std::vector<std::vector<float>>& weights, std::vector<float>& biases) override;
private:
    Optimizer* optimizer;
};

#endif // OPTIMISER_H
