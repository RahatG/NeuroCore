#include "InterfaceEngine.h"
#include "../training/LossFunctions/CrossEntropyLoss.h"
#include "../training/Metrics/Accuracy.h"
#include "../data/Preprocessing/TextCleaner.h"
#include "../data/Tokenizer.h"
#include "../utils/FileUtils.h"
#include <algorithm> // For std::min
#include <random>

InterfaceEngine::InterfaceEngine(const std::string& data_path, const std::string& model_output_path)
    : network(), nlp_processor(), logger(INFO), config("../config/config.json") {
    // Initialize with data and model paths
    DataLoader data_loader(data_path);
    training_data = data_loader.load_data();

    // Initialize loss function and metric
    loss_fn = std::make_unique<CrossEntropyLoss>();
    metric_fn = std::make_unique<Accuracy>();

    // Load model if exists
    if (FileUtils::file_exists(model_output_path + "model.bin")) {
        load_model(model_output_path + "model.bin");
        logger.log("Model loaded from " + model_output_path + "model.bin");
    } else {
        logger.log("No existing model found. Starting with a new model.");
    }
}

std::vector<float> InterfaceEngine::predict(const std::string& input_text) {
    std::vector<std::string> tokens = nlp_processor.process_text(input_text);

    // Fixed input size
    const size_t fixed_input_size = 100;
    std::vector<float> input_vector(fixed_input_size, 0.0f);

    // Convert tokens to input vector
    for (size_t i = 0; i < std::min(tokens.size(), fixed_input_size); ++i) {
        // Implement embedding lookup or token encoding
        input_vector[i] = nlp_processor.get_token_id(tokens[i]);
    }

    return network.forward(input_vector);
}

void InterfaceEngine::train(int epochs, size_t batch_size) {
    const size_t fixed_input_size = 100; // Ensure consistent input size
    size_t total_batches = (training_data.size() + batch_size - 1) / batch_size;

    for (int epoch = 0; epoch < epochs; ++epoch) {
        logger.log("Starting epoch " + std::to_string(epoch + 1));

        // Shuffle training data to improve training
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(training_data.begin(), training_data.end(), g);

        float epoch_loss = 0.0f;
        float epoch_accuracy = 0.0f;

        for (size_t batch_num = 0; batch_num < total_batches; ++batch_num) {
            size_t start_idx = batch_num * batch_size;
            size_t end_idx = std::min(start_idx + batch_size, training_data.size());

            // Vectors to accumulate gradients over the batch
            float batch_loss = 0.0f;
            float batch_accuracy = 0.0f;

            for (size_t idx = start_idx; idx < end_idx; ++idx) {
                const auto& data = training_data[idx];
                std::vector<std::string> tokens = nlp_processor.process_text(data);

                // Prepare input vector with fixed size
                std::vector<float> input_vector(fixed_input_size, 0.0f);
                for (size_t i = 0; i < std::min(tokens.size(), fixed_input_size); ++i) {
                    input_vector[i] = nlp_processor.get_token_id(tokens[i]);
                }

                // Forward pass
                std::vector<float> output = network.forward(input_vector);

                // Get target and compute loss
                std::vector<float> target = get_target_for_data(data);
                float loss = loss_fn->compute_loss(output, target);
                batch_loss += loss;

                // Compute gradient and backpropagate
                std::vector<float> grad_output = loss_fn->compute_gradient(output, target);
                network.backward(grad_output);

                // Update accuracy
                batch_accuracy += metric_fn->compute(output, target);
            }

            // Update network parameters after processing the batch
            network.update_parameters();

            // Log batch loss and accuracy
            logger.log("Epoch " + std::to_string(epoch + 1) + ", Batch " + std::to_string(batch_num + 1) +
                       "/" + std::to_string(total_batches) + ": Loss = " + 
                       std::to_string(batch_loss / (end_idx - start_idx)) +
                       ", Accuracy = " + std::to_string(batch_accuracy / (end_idx - start_idx)));

            epoch_loss += batch_loss;
            epoch_accuracy += batch_accuracy;
        }

        // Log epoch metrics
        logger.log("Epoch " + std::to_string(epoch + 1) + " completed. Average Loss: " +
                   std::to_string(epoch_loss / training_data.size()) +
                   ", Average Accuracy: " + std::to_string(epoch_accuracy / training_data.size()));
    }

    // Save the trained model
    save_model("../Model/model.bin");
    logger.log("Model saved after training.");
}

std::vector<float> InterfaceEngine::get_target_for_data(const std::string& data) {
    // Implement logic to convert data to target vectors
    // For this example, we will generate a dummy target vector
    std::vector<float> target(10, 0.0f); // Assuming 10 classes
    int random_class = std::hash<std::string>{}(data) % 10;
    target[random_class] = 1.0f;
    return target;
}

float InterfaceEngine::calculate_loss(const std::vector<float>& predictions, const std::vector<float>& targets) {
    return loss_fn->compute_loss(predictions, targets);
}

std::vector<float> InterfaceEngine::calculate_gradient(const std::vector<float>& predictions, const std::vector<float>& targets) {
    return loss_fn->compute_gradient(predictions, targets);
}

void InterfaceEngine::save_model(const std::string& path) {
    // Implement model saving logic
    network.save(path);
}

void InterfaceEngine::load_model(const std::string& path) {
    // Implement model loading logic
    network.load(path);
}
