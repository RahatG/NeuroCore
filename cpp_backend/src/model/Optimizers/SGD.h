#include "Optimizer.h"

class SGD : public Optimizer {
public:
    SGD(float learning_rate);
    void update(std::vector<std::vector<float>>& weights,
                const std::vector<std::vector<float>>& weight_grads,
                std::vector<float>& biases,
                const std::vector<float>& bias_grads) override;
private:
    float lr;
};
