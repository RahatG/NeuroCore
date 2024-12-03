// Logger.cpp
#include "Logger.h"
#include <iostream>
#include <fstream>
#include <ctime>

Logger::Logger(LogLevel level) : current_level(level) {}

void Logger::log(const std::string& message, LogLevel level) {
    if(level < current_level) return;

    std::time_t now = std::time(nullptr);
    char buf[100];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    std::string log_message = std::string(buf) + " - " + message;

    switch(level) {
        case INFO:
            std::cout << "[INFO] " << log_message << std::endl;
            break;
        case DEBUG:
            std::cout << "[DEBUG] " << log_message << std::endl;
            break;
        case ERROR:
            std::cerr << "[ERROR] " << log_message << std::endl;
            break;
    }

    // Optionally, write to a log file
}
