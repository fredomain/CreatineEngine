#include "Logger.h"

namespace CE {

    //std::unordered_map<LogFileType, std::ofstream> Logger::staticLogFiles;

    Logger::Logger(const std::string& filePath) {
        auto dir = std::filesystem::path(filePath).parent_path();
        if (!dir.empty()) {
            std::filesystem::create_directories(dir);
        }
        logFile.open(filePath, std::ios::out | std::ios::app);
    }

    Logger::~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    void Logger::log(
        const std::string& message,
        LogLevel level,
        const std::string& category,
        LogOutput output) {
        if (level < minimumLogLevel) return;

        if (output == LogOutput::Terminal || output == LogOutput::Both) {
            std::string color = getLevelColor(level);
            std::print("{}{} [Thread {}] {}\x1b[0m\n",
                color,
                buildLogLabel(category, level),
                std::this_thread::get_id(),
                message);
        }

        if ((output == LogOutput::File || output == LogOutput::Both) && logFile.is_open()) {
            logFile << buildLogLabel(category, level)
                << " [Thread " << std::this_thread::get_id() << "] "
                << message << std::endl;
        }
    }

    void Logger::logMessage(
        LogFileType type,
        const std::string& message,
        LogLevel level,
        const std::string& category,
        LogOutput output)
    {
        if (level < minimumLogLevel) return;

        // Terminal
        if (output == LogOutput::Terminal || output == LogOutput::Both) {
            std::string color = getLevelColor(level);
            std::print("{}{} [Thread {}] {}\x1b[0m\n",
                color,
                buildLogLabel(category, level),
                std::this_thread::get_id(),
                message);
        }

        // Open or resuse persistent streams
        auto& file = staticLogFiles[type];
        if (output == LogOutput::File || output == LogOutput::Both) {            
            if (!file.is_open()) {
                std::string path;
                switch (type) {
                case LogFileType::Engine:
                    path = baseLogDirectory + "Engine/" + generateFilename(); break;
                case LogFileType::Game:
                    path = baseLogDirectory + "Game/" + generateFilename(); break;
                case LogFileType::Audio:
                    path = baseLogDirectory + "Audio/" + generateFilename(); break;
                case LogFileType::Graphics:
                    path = baseLogDirectory + "Graphics/" + generateFilename(); break;
                case LogFileType::Network:
                    path = baseLogDirectory + "Network/" + generateFilename(); break;
                }

                auto dir = std::filesystem::path(path).parent_path();
                if (!dir.empty()) {
                    std::filesystem::create_directories(dir);
                }

                file.open(path, std::ios::out | std::ios::app);
            }

            // if the file is finally opened
            if (file.is_open()) {
                file << buildLogLabel(category, level)
                    << " [Thread " << std::this_thread::get_id() << "] "
                    << message << std::endl;
            }
        }
    }

    void Logger::setMinimumLogLevel(LogLevel level) {
        minimumLogLevel = level;
    }

    LogLevel Logger::getMinimumLogLevel() {
        return minimumLogLevel;
    }

    void Logger::setLogDirectory(std::string logDirectory) {
        baseLogDirectory = logDirectory;
    }

    std::string Logger::generateFilename() {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);

        std::tm tm;
        localtime_s(&tm, &now_c);

        return formatTimestamp(tm, "%d-%m-%Y_%H-%M-%S") + ".log";
    }

    std::string Logger::buildLogLabel(const std::string& category, LogLevel level) {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);

        std::tm tm;
        localtime_s(&tm, &now_c);

        std::ostringstream oss;
        oss << "[" << formatTimestamp(tm, "%d-%m-%Y %H:%M:%S") << "]"
            << "[" << getLevelString(level) << "]"
            << "[" << category << "]";
        return oss.str();
    }

    std::string Logger::formatTimestamp(const std::tm& tm, const std::string& format) {
        std::ostringstream oss;
        oss << std::put_time(&tm, format.c_str());
        return oss.str();
    }

    void Logger::shutdown() {
        for (auto& [type, file] : staticLogFiles) {
            if (file.is_open()) {
                file.close();
            }
        }
        staticLogFiles.clear();
    }

} // namespace CE
