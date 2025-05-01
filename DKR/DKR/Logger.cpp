#include "Logger.h"
#include <fstream>
#include <ctime>

void Logger::log(const std::string& message) {
    std::ofstream file("log.txt", std::ios::app);
    if (file) {
        std::time_t now = std::time(nullptr);
        file << std::ctime(&now) << ": " << message << "\n";
    }
}
