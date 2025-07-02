#include "Logger.h"

namespace CE {

    /**
     * @brief Constructs a Logger object and opens a log file for writing, creating any necessary directories in the file path.
     * @param filePath The path to the log file to open or create.
     */
    Logger::Logger(const std::string& filePath) {
        auto dir = std::filesystem::path(filePath).parent_path();
        if (!dir.empty()) {
            std::filesystem::create_directories(dir);
        }
        logFile.open(filePath, std::ios::out | std::ios::app);
    }

    /**
     * @brief Destroys the Logger object and closes the associated log file.
     */
    Logger::~Logger() {
        logFile.close();
    }

    /**
     * @brief Logs a message with a specified log level, category, and output destination.
     * @param message The message to be logged.
     * @param level The severity level of the log message.
     * @param category The category or module associated with the log message.
     * @param output Specifies where the log message should be sent (terminal, file, or both).
     */
    void Logger::log(const std::string& message, LogLevel level, const std::string& category, LogOutput output) {
        if (level < minimumLogLevel) return;

        if (output == LogOutput::Terminal || output == LogOutput::Both) {
            std::string color = logLevelProperties[static_cast<int>(level)].ansiColorCode;
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

    /**
     * @brief Logs a message to a file, the terminal, or both, with specified log type, level, category, and output destination.
     * @param type The type of log file to write to (e.g., Engine, Game, Audio, Graphics, Network).
     * @param message The message to be logged.
     * @param level The severity level of the log message.
     * @param category The category or module associated with the log message.
     * @param output Specifies where to output the log message (file, terminal, or both).
     */
    void Logger::logMessage(LogFileType type,
        const std::string& message,
        LogLevel level,
        const std::string& category,
        LogOutput output)
    {
        if (level < minimumLogLevel) return;

        std::string path;
        switch (type) {
        case LogFileType::Engine:   path = baseLogDirectory + "Engine/" + generateFilename(); break;
        case LogFileType::Game:     path = baseLogDirectory + "Game/" + generateFilename(); break;
        case LogFileType::Audio:    path = baseLogDirectory + "Audio/" + generateFilename(); break;
        case LogFileType::Graphics: path = baseLogDirectory + "Graphics/" + generateFilename(); break;
        case LogFileType::Network:  path = baseLogDirectory + "Network/" + generateFilename(); break;
        }

        auto dir = std::filesystem::path(path).parent_path();
        if (!dir.empty()) {
            std::filesystem::create_directories(dir);
        }

        std::ofstream file(path, std::ios::out | std::ios::app);

        if (output == LogOutput::Terminal || output == LogOutput::Both) {
            std::string color = logLevelProperties[static_cast<int>(level)].ansiColorCode;
            std::print("{}{} [Thread {}] {}\x1b[0m\n",
                color,
                buildLogLabel(category, level),
                std::this_thread::get_id(),
                message);
        }

        if ((output == LogOutput::File || output == LogOutput::Both) && file.is_open()) {
            file << buildLogLabel(category, level)
                << " [Thread " << std::this_thread::get_id() << "] "
                << message << std::endl;
        }
    }

    /**
     * @brief Sets the minimum log level for the logger.
     * @param level The minimum log level to be set. Messages below this level will be ignored.
     */
    void Logger::setMinimumLogLevel(LogLevel level) {
        minimumLogLevel = level;
    }

    /**
     * @brief Retrieves the minimum log level currently set for the logger.
     * @return The minimum LogLevel value configured for the logger.
     */
    LogLevel Logger::getMinimumLogLevel() {
        return minimumLogLevel;
    }

    /**
     * @brief Generates a log filename based on the current date and time.
     * @return A string containing the generated filename in the format 'DD-MM-YYYY_HH-MM-SS.log', representing the current local date and time.
     */
    std::string Logger::generateFilename() {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);

        std::tm tm;
        localtime_s(&tm, &now_c);

        return formatTimestamp(tm, "%d-%m-%Y_%H-%M-%S") + ".log";
    }

    /**
     * @brief Builds a formatted log label string containing the current timestamp, log level, and category.
     * @param category The log category to include in the label.
     * @param level The log level to include in the label.
     * @return A string containing the formatted log label with timestamp, log level, and category.
     */
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

    /**
     * @brief Formats a timestamp according to the specified format string.
     * @param tm The time structure representing the date and time to format.
     * @param format The format string specifying how the timestamp should be formatted (e.g., "%Y-%m-%d %H:%M:%S").
     * @return A string containing the formatted timestamp.
     */
    std::string Logger::formatTimestamp(const std::tm& tm, const std::string& format) {
        std::ostringstream oss;
        oss << std::put_time(&tm, format.c_str());
        return oss.str();
    }

} // namespace CE
