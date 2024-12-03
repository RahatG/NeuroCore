// Logger.h
#ifndef LOGGER_H
#define LOGGER_H

#include <string>

enum LogLevel {
    INFO,
    DEBUG,
    ERROR
};

class Logger {
public:
    Logger(LogLevel level = INFO);
    void log(const std::string& message, LogLevel level = INFO);
private:
    LogLevel current_level;
};

#endif // LOGGER_H
