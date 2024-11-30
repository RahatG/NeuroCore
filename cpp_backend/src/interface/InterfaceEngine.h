#ifndef INTERFACEENGINE_H
#define INTERFACEENGINE_H

#include <string>
#include <vector>
#include "../model/NeuralNetwork.h"
#include "../nlp/NLPProcessor.h"

class InterfaceEngine {
public:
    InterfaceEngine(const std::string& data_path, const std::string& model_output_path);
    std::vector<float> predict(const std::string& input_text);
    void train(int epochs);

private:
    NeuralNetwork network;
    NLPProcessor nlp_processor;

    // Declare the training data member variable
    std::vector<std::string> training_data;


    // Declare the member functions used in InterfaceEngine.cpp
    std::vector<float> get_target_for_data(const std::string& data);
    float calculate_loss(const std::vector<float>& predictions, const std::vector<float>& targets);
    std::vector<float> calculate_gradient(const std::vector<float>& predictions, const std::vector<float>& targets);
};

#endif // INTERFACEENGINE_H
