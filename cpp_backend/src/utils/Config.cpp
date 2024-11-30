// Config.cpp
#include "Config.h"
#include <fstream>
#include <stdexcept>

Config::Config(const std::string& config_path) {
    std::ifstream infile(config_path);
    if (!infile.is_open()) {
        throw std::runtime_error("Failed to open config file.");
    }
    infile >> config_json;
    infile.close();
}

template<typename T>
T Config::get(const std::string& key) const {
    if(config_json.contains(key)) {
        return config_json[key].get<T>();
    }
    throw std::runtime_error("Key not found in config.");
}

// Explicit template instantiation
template int Config::get<int>(const std::string&) const;
template float Config::get<float>(const std::string&) const;
template std::string Config::get<std::string>(const std::string&) const;
// Add more as needed
