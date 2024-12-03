#ifndef INTERFACEENGINE_H
#define INTERFACEENGINE_H

#include <string>
#include <vector>
#include <memory>
#include "../model/NeuralNetwork.h"
#include "../nlp/NLPProcessor.h"
#include "../utils/Logger.h"
#include "../training/LossFunctions/LossFunction.h"
#include "../training/Metrics/Metric.h"
#include "../data/DataLoader.h"
#include "../utils/Config.h"
#include "../training/Trainer.h"

class InterfaceEngine {
public:
    InterfaceEngine(const std::string& data_path, const std::string& model_output_path);
    std::vector<float> predict(const std::string& input_text);
    void train(int epochs, size_t batch_size);

    // Save and load model
    void save_model(const std::string& path);
    void load_model(const std::string& path);

private:
    NeuralNetwork network;
    NLPProcessor nlp_processor;
    Logger logger;

    // Training data
    std::vector<std::string> training_data;

    // Loss function and metric
    std::unique_ptr<LossFunction> loss_fn;
    std::unique_ptr<Metric> metric_fn;

    // Configuration
    Config config;

    // Helper functions
    std::vector<float> get_target_for_data(const std::string& data);
    float calculate_loss(const std::vector<float>& predictions, const std::vector<float>& targets);
    std::vector<float> calculate_gradient(const std::vector<float>& predictions, const std::vector<float>& targets);
};

#endif // INTERFACEENGINE_H
