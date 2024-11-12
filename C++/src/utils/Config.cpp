#include "Config.h"
#include <fstream>

Config::Config(const std::string& config_path) {
    std::ifstream infile(config_path);
    infile >> config_json;
}

std::string Config::get(const std::string& key) {
    return config_json[key];
}
