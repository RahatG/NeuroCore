#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork()
    : optimiser(new Optimiser("Adam", 0.001f)) {
    dense_layers.emplace_back(DenseLayer(100, 50));
    dense_layers.emplace_back(DenseLayer(50, 10));
}

std::vector<float> NeuralNetwork::forward(const std::vector<float>& input) {
    std::vector<float> output = input;
    output = dense_layers[0].forward(output);
    output = relu.activate(output);
    output = dense_layers[1].forward(output);
    output = softmax.activate(output);
    return output;
}

void NeuralNetwork::backward(const std::vector<float>& loss_grad) {
    std::vector<float> grad = softmax.derivative(loss_grad);
    grad = dense_layers[1].backward(grad);
    grad = relu.derivative(grad);
    grad = dense_layers[0].backward(grad);
    // Store gradients if needed
}

void NeuralNetwork::update_parameters() {
    for(auto &layer : dense_layers) {
        // Placeholder: Update parameters using optimiser
    }
    optimiser->update(/*weights*/, /*biases*/);
}
