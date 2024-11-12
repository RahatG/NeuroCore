#ifndef INTERFACEENGINE_H
#define INTERFACEENGINE_H

#include <string>
#include <vector>
#include "NeuralNetwork.h"
#include "NLPProcessor.h"

class InterfaceEngine {
public:
    InterfaceEngine(const std::string& data_path, const std::string& model_output_path);
    std::vector<float> predict(const std::string& input_text);
    void train(int epochs);
private:
    NeuralNetwork network;
    NLPProcessor nlp_processor;
};

#endif // INTERFACEENGINE_H