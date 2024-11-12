#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <vector>
#include "Layers/DenseLayer.h"
#include "Layers/ConvolutionLayer.h"
#include "Layers/RecurrentLayer.h"
#include "Layers/TransformerLayer.h"
#include "Activation/ReLU.h"
#include "Activation/Sigmoid.h"
#include "Activation/Softmax.h"
#include "Activation/Tanh.h"
#include "Optimisers/Optimiser.h"

class NeuralNetwork {
public:
    NeuralNetwork();
    std::vector<float> forward(const std::vector<float>& input);
    void backward(const std::vector<float>& loss_grad);
    void update_parameters();
private:
    std::vector<DenseLayer> dense_layers;
    ReLU relu;
    Sigmoid sigmoid;
    Softmax softmax;
    Tanh tanh;
    Optimiser* optimiser;
};

#endif // NEURALNETWORK_H
