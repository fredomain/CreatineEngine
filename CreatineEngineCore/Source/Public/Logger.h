#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <print>

namespace CE {

    enum class LogLevel {
        Verbose,
        Debug,
        Info,
        Warn,
        Error,
        Critical
    };

    struct LogLevelInfo {
        const char* name;
        const char* ansiColorCode;
    };

    inline constexpr LogLevelInfo logLevelProperties[] = {
        { "VERBOSE",  "\x1b[90m" }, // Dark gray
        { "DEBUG",    "\x1b[32m" }, // Green
        { "INFO",     "\x1b[0m"  }, // Default
        { "WARN",     "\x1b[33m" }, // Yellow
        { "ERROR",    "\x1b[91m" }, // Bright red
        { "CRITICAL", "\x1b[31m" }  // Red
    };

    inline std::string getLevelString(LogLevel level) {
        return logLevelProperties[static_cast<int>(level)].name;
    }

    inline std::string getLevelColor(LogLevel level) {
        return logLevelProperties[static_cast<int>(level)].ansiColorCode;
    }

    class Logger {
    public:
        Logger(const std::string& filePath);
        ~Logger();

        void setMinimumLogLevel(LogLevel level);
        void log(const std::string& message,
            LogLevel level = LogLevel::Info,
            const std::string& category = "General");

    private:
        std::ofstream logFile;
        LogLevel minLogLevel = LogLevel::Verbose;

        void writeToOutput(const std::string& category, LogLevel level, const std::string& message);
        static std::string getCurrentTimestamp();
    };

} // namespace CE

#endif // LOGGER_H
