#include "Logger.h"
#include <fstream>
#include <ctime>
#include <iomanip>

void Logger::log(const std::string& message) {
    std::ofstream file("log.txt", std::ios::app);
    if (file) {
        std::time_t now = std::time(nullptr);
        char buffer[100];
        ctime_s(buffer, sizeof(buffer), &now);  // Safe version
        buffer[strcspn(buffer, "\n")] = 0;      // Remove newline from ctime_s
        file << buffer << ": " << message << "\n";
    }
}
