#include "TimingManager.h"
#include "Logger.h"
#include <thread>
#include <format>

namespace CE {


    TimingManager::TimingManager(double fixedTimeStep, int targetFPS)
        : deltaTime(0.0f), gameDeltaTime(0.0f),
        accumulatedTime(0.0), gameAccumulatedTime(0.0),
        targetFPS(targetFPS),
        targetFrameDuration((targetFPS > 0) ? 1.0 / static_cast<double>(targetFPS) : 0.0),
        gameSpeed(1.0), paused(false)
#ifdef TIMING_USE_FIXED_STEP
        , fixedTimeStep(fixedTimeStep), fixedTimeAccumulator(0.0)
#endif
    {
    }


    void TimingManager::start() {
        startTime = Clock::now();
        lastTime = startTime;
        deltaTime = 0.0f;
        gameDeltaTime = 0.0f;
        accumulatedTime = 0.0;
        gameAccumulatedTime = 0.0;
        paused = false;

        speedHistory.clear();
        speedHistory.push_back({ gameSpeed, 0.0 });
#ifdef TIMING_USE_FIXED_STEP
        fixedTimeAccumulator = 0.0;
#endif
    }

    void TimingManager::reset() {
        start();
    }

    void TimingManager::update() {
		TimePoint now = Clock::now();                                       // Captures the current time
		std::chrono::duration<float> diff = now - lastTime;                 // Calculates the time difference between the last update and now
		deltaTime = diff.count();                                           // Converts the time difference to seconds (float)
		accumulatedTime += static_cast<double>(deltaTime);                  // Accumulates the real time in seconds

        if (paused) {
			gameDeltaTime = 0.0f;                                           // If paused, game delta time is zero
        }
        else {
			gameDeltaTime = deltaTime * static_cast<float>(gameSpeed);      // Calculates the game delta time based on the game speed
			gameAccumulatedTime += static_cast<double>(gameDeltaTime);      //  Accumulates the game time in seconds
        }

		lastTime = now;                                                     // Updates the last time to the current time

#ifdef TIMING_USE_FIXED_STEP
		fixedTimeAccumulator += deltaTime;                                  // Accumulates the real time for fixed step updates
#endif
    }

    void TimingManager::pause() {
        if (!paused) {
            paused = true;
            Logger::logMessage(LogFileType::Engine, "Game paused", LogLevel::Info, "Timing Manager");
        }
    }

    void TimingManager::resume() {
        if (paused) {
            paused = false;
            Logger::logMessage(LogFileType::Engine, "Game resumed", LogLevel::Info, "Timing Manager");
        }
    }

    bool TimingManager::isPaused() const {
        return paused;
    }

    void TimingManager::frameRateControl() {
        if (targetFPS <= 0 || paused) {
            return;
        }

        TimePoint frameEnd = Clock::now();
        std::chrono::duration<double> frameDuration = frameEnd - lastTime;

        double sleepTime = targetFrameDuration - frameDuration.count();
        if (sleepTime > 0.0) {
            std::this_thread::sleep_for(std::chrono::duration<double>(sleepTime));
        }
    }

    float TimingManager::getCurrentFPS() const {
        return (deltaTime > 0.0f) ? (1.0f / deltaTime) : 0.0f;
    }

    void TimingManager::setTargetFPS(int fps) {
        targetFPS = fps;
        targetFrameDuration = (fps > 0) ? 1.0 / static_cast<double>(fps) : 0.0;
    }

    int TimingManager::getTargetFPS() const {
        return targetFPS;
    }

    double TimingManager::getTargetFrameDuration() const {
        return targetFrameDuration;
    }

    void TimingManager::setGameSpeed(double speed) {
        if (speed != gameSpeed) {
            speedHistory.push_back({ speed, accumulatedTime });
            gameSpeed = speed;

            std::string message = std::format(
                "[TimingManager] Game speed changed to {:.2f} at {:.3f}s",
                speed, accumulatedTime
            );
            Logger::logMessage(LogFileType::Engine, message, LogLevel::Info, "Timing Manager");
        }
    }

    double TimingManager::getGameSpeed() const {
        return gameSpeed;
    }

    float TimingManager::getDeltaTime() const {
        return deltaTime;
    }

    float TimingManager::getGameDeltaTime() const {
        return paused ? 0.0f : gameDeltaTime;
    }

    double TimingManager::getTotalTime() const {
        return accumulatedTime;
    }

    double TimingManager::getGameTime() const {
        return gameAccumulatedTime;
    }

    double TimingManager::getTimeDrift() const {
        auto now = Clock::now();
        std::chrono::duration<double> realElapsed = now - startTime;
        return accumulatedTime - realElapsed.count();
    }

    void TimingManager::correctDrift() {
        auto now = Clock::now();
        std::chrono::duration<double> realElapsed = now - startTime;
        double driftFactor = realElapsed.count() / accumulatedTime;

        accumulatedTime = realElapsed.count();

        gameAccumulatedTime = 0.0;
        for (size_t i = 1; i < speedHistory.size(); ++i) {
            double segmentTime = speedHistory[i].timeAtChange - speedHistory[i - 1].timeAtChange;
            segmentTime *= driftFactor;
            gameAccumulatedTime += segmentTime * speedHistory[i - 1].speed;
            speedHistory[i].timeAtChange = speedHistory[i - 1].timeAtChange + segmentTime;
        }

        if (!speedHistory.empty()) {
            double lastSegmentTime = accumulatedTime - speedHistory.back().timeAtChange;
            gameAccumulatedTime += lastSegmentTime * speedHistory.back().speed;
        }

        speedHistory.clear();
        speedHistory.push_back({ gameSpeed, accumulatedTime });
    }

#ifdef TIMING_USE_FIXED_STEP
    bool TimingManager::shouldStepFixedUpdate() {
        if (fixedTimeAccumulator >= fixedTimeStep) {
            fixedTimeAccumulator -= fixedTimeStep;
            return true;
        }
        return false;
    }

    double TimingManager::getFixedTimeStep() const {
        return fixedTimeStep;
    }
#endif

}
