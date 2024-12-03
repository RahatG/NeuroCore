#include "Trainer.h"
#include "../utils/Logger.h"
#include "../nlp/NLPProcessor.h"

Trainer::Trainer(NeuralNetwork& network, LossFunction& loss_fn, Metric& metric, DataLoader& data_loader, NLPProcessor& nlp_processor)
    : net(network), loss(loss_fn), metric_fn(metric), loader(data_loader), nlp(nlp_processor) {}

void Trainer::train(int epochs) {
    Logger logger(INFO);
    for(int epoch = 1; epoch <= epochs; ++epoch) {
        float epoch_loss = 0.0f;
        float epoch_metric = 0.0f;
        std::vector<std::string> data = loader.load_data();
        for(const auto &text : data) {
            std::vector<std::string> tokens = nlp.process_text(text);
            // Placeholder: Convert tokens to input vector
            std::vector<float> input(100, 1.0f); // Example input
            std::vector<float> targets(10, 0.0f); // Example target
            input = net.forward(input);
            float current_loss = loss.compute_loss(input, targets);
            epoch_loss += current_loss;
            std::vector<float> grad = loss.compute_gradient(input, targets);
            net.backward(grad);
            net.update_parameters();
            epoch_metric += metric_fn.compute(input, targets);
        }
        logger.log("Epoch " + std::to_string(epoch) + " Loss: " + std::to_string(epoch_loss / data.size()) + " Metric: " + std::to_string(epoch_metric / data.size()));
    }
}
