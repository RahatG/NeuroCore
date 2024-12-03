// Config.h
#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <nlohmann/json.hpp>

class Config {
public:
    Config(const std::string& config_path);

    template<typename T>
    T get(const std::string& key) const;

private:
    nlohmann::json config_json;
};

#endif // CONFIG_H
