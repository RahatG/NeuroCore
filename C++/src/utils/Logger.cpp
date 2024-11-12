#include "Logger.h"
#include <iostream>
#include <fstream>
#include <ctime>

Logger::Logger() {}

void Logger::log(const std::string& message) {
    std::time_t now = std::time(nullptr);
    char buf[100];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    std::string log_message = std::string(buf) + " - " + message;
    std::cout << log_message << std::endl;
    // Also write to a log file if needed
}
