#include "Logger.h"
#include <chrono>

namespace CE {

    Logger::Logger(const std::string& filePath) {
        logFile.open(filePath, std::ios::out | std::ios::app);
    }

    Logger::~Logger() {
        logFile.close();
    }

    void Logger::setMinimumLogLevel(LogLevel level) {
        minLogLevel = level;
    }

    void Logger::log(const std::string& message, LogLevel level, const std::string& category) {
        if (level < minLogLevel) return;
        writeToOutput(category, level, message);
    }

    void Logger::writeToOutput(const std::string& category, LogLevel level, const std::string& message) {
        std::string timestamp = getCurrentTimestamp();
        std::string levelStr = getLevelString(level);
        std::string color = getLevelColor(level);

        // Terminal (with color)
        std::print("{}[{}][{}][{}] {}\x1b[0m\n", color, timestamp, levelStr, category, message);

        // File (plain text)
        if (logFile.is_open()) {
            logFile << "[" << timestamp << "][" << levelStr << "][" << category << "] " << message << std::endl;
        }
    }

    std::string Logger::getCurrentTimestamp() {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);

        std::tm tm;
        localtime_s(&tm, &now_c);

        std::ostringstream oss;
        oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }

}
