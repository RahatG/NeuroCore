#ifndef RECURRENTLAYER_H
#define RECURRENTLAYER_H

#include <vector>

class RecurrentLayer {
public:
    RecurrentLayer(int input_size, int hidden_size);
    std::vector<float> forward(const std::vector<float>& input);
    std::vector<float> backward(const std::vector<float>& grad_output);
private:
    int input_size;
    int hidden_size;
    std::vector<std::vector<float>> weights_input;
    std::vector<std::vector<float>> weights_hidden;
    std::vector<float> biases;
    std::vector<float> hidden_state;
};

#endif // RECURRENTLAYER_H
