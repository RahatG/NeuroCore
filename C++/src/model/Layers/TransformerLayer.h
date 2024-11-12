#ifndef TRANSFORMERLAYER_H
#define TRANSFORMERLAYER_H

#include <vector>

class TransformerLayer {
public:
    TransformerLayer(int model_size, int num_heads);
    std::vector<float> forward(const std::vector<float>& input);
    std::vector<float> backward(const std::vector<float>& grad_output);
private:
    int model_size;
    int num_heads;
    // Transformer-specific components
};

#endif // TRANSFORMERLAYER_H
