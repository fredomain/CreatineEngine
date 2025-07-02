#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <print>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <filesystem>
#include <thread>

namespace CE {

    enum class LogLevel {
        Verbose,
        Debug,
        Info,
        Warn,
        Error,
        Critical
    };

    enum class LogFileType {
        Engine,
        Game,
        Audio,
        Graphics,
        Network
    };

    enum class LogOutput {
        File,
        Terminal,
        Both
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

        void log(const std::string& message,
            LogLevel level = LogLevel::Info,
            const std::string& category = "General",
            LogOutput output = LogOutput::Both);

        static void logMessage(LogFileType type,
            const std::string& message,
            LogLevel level = LogLevel::Info,
            const std::string& category = "General",
            LogOutput output = LogOutput::Both);

        static void setMinimumLogLevel(LogLevel level);
        static LogLevel getMinimumLogLevel();

    private:
        std::ofstream logFile;

        static std::string generateFilename();
        static std::string buildLogLabel(const std::string& category, LogLevel level);
        static std::string formatTimestamp(const std::tm& tm, const std::string& format);

        inline static const std::string baseLogDirectory = "Logs/";
        inline static LogLevel minimumLogLevel = LogLevel::Verbose;
    };

} // namespace CE

#endif // LOGGER_H
