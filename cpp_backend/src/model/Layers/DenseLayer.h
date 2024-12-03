#ifndef DENSELAYER_H
#define DENSELAYER_H

#include <vector>

class DenseLayer {
public:
    DenseLayer(int input_size, int output_size);
    
    // Forward and Backward Pass
    std::vector<float> forward(const std::vector<float>& input);
    std::vector<float> backward(const std::vector<float>& grad_output);

    // Const Accessors for weights and biases
    const std::vector<std::vector<float>>& get_weights() const;
    const std::vector<float>& get_biases() const;

    // Non-const Accessors for weights and biases (for updating)
    std::vector<std::vector<float>>& get_weights();
    std::vector<float>& get_biases();

    // Const Accessors for gradients
    const std::vector<std::vector<float>>& get_weight_gradients() const;
    const std::vector<float>& get_bias_gradients() const;

    // Non-const Accessors for gradients (for accumulating gradients)
    std::vector<std::vector<float>>& get_weight_gradients();
    std::vector<float>& get_bias_gradients();

    // Reset gradients after parameter updates
    void reset_gradients();

private:
    int input_size;
    int output_size;
    std::vector<std::vector<float>> weights;
    std::vector<float> biases;
    std::vector<float> input;

    // Gradients
    std::vector<std::vector<float>> weight_gradients;
    std::vector<float> bias_gradients;
};

#endif // DENSELAYER_H
