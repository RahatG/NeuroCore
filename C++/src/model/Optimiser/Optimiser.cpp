#include "Optimiser.h"
#include "SGD.h"
#include "Adam.h"
#include "RMSProp.h"
#include <stdexcept>

Optimiser::Optimiser(const std::string& type, float lr) {
    if(type == "SGD") {
        optimizer = new SGD(lr);
    }
    else if(type == "Adam") {
        optimizer = new Adam(lr, 0.9f, 0.999f, 1e-8f);
    }
    else if(type == "RMSProp") {
        optimizer = new RMSProp(lr, 0.9f, 1e-8f);
    }
    else {
        throw std::invalid_argument("Unsupported optimizer type.");
    }
}

void Optimiser::update(std::vector<std::vector<float>>& weights, std::vector<float>& biases) {
    optimizer->update(weights, biases);
}
