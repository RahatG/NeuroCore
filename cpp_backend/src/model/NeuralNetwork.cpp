#include "NeuralNetwork.h"
#include "Optimizers/Adam.h"
#include <cmath>
#include <iostream>
#include <fstream>

// Constructor with Adam Optimizer
NeuralNetwork::NeuralNetwork()
        : optimizer(std::make_unique<Adam>(0.001f, 0.9f, 0.999f, 1e-8f)), logger(INFO) { // Using Adam optimizer
    // Initialize Dense Layers
    dense_layers.emplace_back(DenseLayer(100, 50));
    dense_layers.emplace_back(DenseLayer(50, 10));

    // Initialize Gradient Storage based on layers
    for(auto &layer : dense_layers) {
        weight_grads.emplace_back(layer.get_weight_gradients()); // Each layer's weight gradients
        bias_grads.emplace_back(layer.get_bias_gradients());     // Each layer's bias gradients
    }
}

// Forward Pass through the Network
std::vector<float> NeuralNetwork::forward(const std::vector<float>& input) {
    std::vector<float> output = input;
    output = dense_layers[0].forward(output);
    output = relu.activate(output);
    output = dense_layers[1].forward(output);
    output = softmax.activate(output);
    return output;
}

// Backward Pass through the Network
std::vector<float> NeuralNetwork::backward(const std::vector<float>& loss_grad) {
    // Reset gradients before accumulating new ones
    for (std::size_t i = 0; i < dense_layers.size(); ++i) {
        // Reset weight gradients
        for(auto &wg : weight_grads[i]) {
            std::fill(wg.begin(), wg.end(), 0.0f);
        }
        // Reset bias gradients
        std::fill(bias_grads[i].begin(), bias_grads[i].end(), 0.0f);
    }

    // Backward Pass
    std::vector<float> grad = softmax.derivative(loss_grad);
    grad = dense_layers[1].backward(grad);
    grad = relu.derivative(grad);
    grad = dense_layers[0].backward(grad);

    // Collect gradients from each layer
    for (std::size_t i = 0; i < dense_layers.size(); ++i) {
        auto& layer_weight_grads = dense_layers[i].get_weight_gradients();
        auto& layer_bias_grads = dense_layers[i].get_bias_gradients();
        weight_grads[i] = layer_weight_grads;
        bias_grads[i] = layer_bias_grads;
    }

    return grad;
}

// Update Network Parameters using Optimizer
void NeuralNetwork::update_parameters() {
    // Collect all weights and biases and their gradients
    std::vector<std::vector<float>> all_weights;
    std::vector<std::vector<float>> all_weight_grads;
    std::vector<float> all_biases;
    std::vector<float> all_bias_grads;

    for (std::size_t i = 0; i < dense_layers.size(); ++i) {
        auto& w = dense_layers[i].get_weights(); // std::vector<std::vector<float>>
        auto& b = dense_layers[i].get_biases();  // std::vector<float>
        auto& wg = weight_grads[i];              // std::vector<std::vector<float>>
        auto& bg = bias_grads[i];                // std::vector<float>

        // Flatten weights and weight gradients
        for(auto& weight_vec : w) {
            all_weights.emplace_back(weight_vec);
        }
        for(auto& weight_grad_vec : wg) {
            all_weight_grads.emplace_back(weight_grad_vec);
        }

        // Flatten biases and bias gradients
        for(auto& bias : b) {
            all_biases.emplace_back(bias);
        }
        for(auto& bias_grad : bg) {
            all_bias_grads.emplace_back(bias_grad);
        }
    }

    // Update using optimizer
    optimizer->update(all_weights, all_weight_grads, all_biases, all_bias_grads);

    // Distribute updated weights and biases back to layers
    size_t idx_w = 0;
    size_t idx_b = 0;
    for(auto& layer : dense_layers) {
        auto& w = layer.get_weights();
        auto& b = layer.get_biases();
        // Assign weights
        for(auto& weight_vec : w) {
            weight_vec = all_weights[idx_w++];
        }
        // Assign biases
        for(auto& bias : b) {
            bias = all_biases[idx_b++];
        }
    }

    // Reset the gradients after the update
    for (std::size_t i = 0; i < dense_layers.size(); ++i) {
        // Reset weight gradients
        for(auto &wg : weight_grads[i]) {
            std::fill(wg.begin(), wg.end(), 0.0f);
        }
        // Reset bias gradients
        std::fill(bias_grads[i].begin(), bias_grads[i].end(), 0.0f);
    }

    logger.log("NeuralNetwork: Parameters updated successfully.");
}

// Save the Model to a Binary File
void NeuralNetwork::save(const std::string& path) {
    std::ofstream ofs(path, std::ios::binary);
    if (!ofs.is_open()) {
        logger.log("Failed to open file for saving: " + path, ERROR);
        return;
    }

    // Save weights and biases
    for (const auto& layer : dense_layers) {
        const auto& weights = layer.get_weights();   // Const accessor
        const auto& biases = layer.get_biases();     // Const accessor

        // Save weights
        for (const auto& neuron_weights : weights) {
            ofs.write(reinterpret_cast<const char*>(neuron_weights.data()), neuron_weights.size() * sizeof(float));
        }

        // Save biases
        ofs.write(reinterpret_cast<const char*>(biases.data()), biases.size() * sizeof(float));
    }

    ofs.close();
    logger.log("NeuralNetwork: Model saved to " + path);
}

// Load the Model from a Binary File
void NeuralNetwork::load(const std::string& path) {
    std::ifstream ifs(path, std::ios::binary);
    if (!ifs.is_open()) {
        logger.log("Failed to open file for loading: " + path, ERROR);
        return;
    }

    // Load weights and biases
    for (auto& layer : dense_layers) {
        auto& weights = layer.get_weights();   // Non-const accessor
        auto& biases = layer.get_biases();     // Non-const accessor

        // Load weights
        for (auto& neuron_weights : weights) {
            ifs.read(reinterpret_cast<char*>(neuron_weights.data()), neuron_weights.size() * sizeof(float));
        }

        // Load biases
        ifs.read(reinterpret_cast<char*>(biases.data()), biases.size() * sizeof(float));
    }

    ifs.close();
    logger.log("NeuralNetwork: Model loaded from " + path);
}
