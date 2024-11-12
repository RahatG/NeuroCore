#ifndef TRAINER_H
#define TRAINER_H

#include "../model/NeuralNetwork.h"
#include "LossFunctions/LossFunction.h"
#include "LossFunctions/CrossEntropyLoss.h"
#include "LossFunctions/MeanSquaredLoss.h"
#include "Metrics/Metric.h"
#include "Metrics/Accuracy.h"
#include "../data/DataLoader.h"
#include "../data/NLPProcessor.h"
#include <vector>
#include <string>

class Trainer {
public:
    Trainer(NeuralNetwork& network, LossFunction& loss_fn, Metric& metric, DataLoader& data_loader, NLPProcessor& nlp_processor);
    void train(int epochs);
private:
    NeuralNetwork& net;
    LossFunction& loss;
    Metric& metric_fn;
    DataLoader& loader;
    NLPProcessor& nlp;
};

#endif // TRAINER_H
