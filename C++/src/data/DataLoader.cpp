#include "DataLoader.h"
#include <fstream>
#include <stdexcept>

DataLoader::DataLoader(const std::string& data_path) : path(data_path) {}

std::vector<std::string> DataLoader::load_data() {
    std::vector<std::string> data;
    std::ifstream infile(path);
    if (!infile.is_open()) {
        throw std::runtime_error("Failed to open data file.");
    }
    std::string line;
    while (std::getline(infile, line)) {
        data.push_back(line);
    }
    infile.close();
    return data;
}
