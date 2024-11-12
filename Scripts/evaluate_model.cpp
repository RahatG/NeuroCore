#include "interface/InterfaceEngine.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if(argc != 3) {
        std::cerr << "Usage: evaluate_model <data_path> <model_output_path>" << std::endl;
        return 1;
    }
    std::string data_path = argv[1];
    std::string model_output_path = argv[2];
    InterfaceEngine engine(data_path, model_output_path);
    // Placeholder: Implement evaluation logic
    std::cout << "Evaluation completed." << std::endl;
    return 0;
}
