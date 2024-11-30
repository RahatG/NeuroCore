#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <vector>
#include <memory>
#include "Layers/DenseLayer.h"
#include "Layers/ConvolutionLayer.h"
#include "Layers/RecurrentLayer.h"
#include "Layers/TransformerLayer.h"
#include "Activation/ReLU.h"
#include "Activation/Sigmoid.h"
#include "Activation/Softmax.h"
#include "Activation/Tanh.h"
#include "Optimizers/Optimizer.h"

class NeuralNetwork {
public:
    NeuralNetwork();
    std::vector<float> forward(const std::vector<float>& input);
    std::vector<float> backward(const std::vector<float>& loss_grad);
    void update_parameters();
private:
    std::vector<DenseLayer> dense_layers;
    ReLU relu;
    Sigmoid sigmoid;
    Activation::Softmax softmax;
    Tanh tanh;
    std::unique_ptr<Optimizer> optimizer;

    // Corrected Gradient Storage
    std::vector<std::vector<std::vector<float>>> weight_grads; // [layer][neuron][weight]
    std::vector<std::vector<float>> bias_grads;               // [layer][bias]
};

#endif // NEURALNETWORK_H
