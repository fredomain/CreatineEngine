#include "TimingManager.h"
#include "Logger.h"
#include <thread>
#include <format>

namespace CE {

    TimingManager::TimingManager(double fixedTimeStep, int targetFPS)
        : deltaTime(0.0f), gameDeltaTime(0.0f),
        gameAccumulatedTime(0.0),
        targetFPS(targetFPS),
        targetFrameDuration((targetFPS > 0) ? 1.0 / static_cast<double>(targetFPS) : 0.0),
        gameSpeed(1.0), paused(false)
#ifdef TIMING_USE_FIXED_STEP
        , fixedTimeStep(fixedTimeStep), fixedTimeAccumulator(0.0)
#endif
    {
        if (targetFPS > 0) {
            targetFrameDurationChrono = std::chrono::duration_cast<Clock::duration>(
                std::chrono::duration<double>(targetFrameDuration)
            );
        }
        else {
            targetFrameDurationChrono = Clock::duration::zero();
        }
    }

    void TimingManager::start() {
        startTime = Clock::now();
        lastTime = startTime;
        now = startTime;
        nextFrameTime = startTime;
        diff = std::chrono::duration<float>::zero();
        deltaTime = 0.0f;
        gameDeltaTime = 0.0f;
        gameAccumulatedTime = 0.0;
        paused = false;

#ifdef TIMING_USE_FIXED_STEP
        fixedTimeAccumulator = 0.0;
#endif
    }

    void TimingManager::reset() {
        start();
    }

    void TimingManager::update() {
        now = Clock::now(); // Capture current time
                
        if (getTargetFPS() > 0) {   // FPS control
            // Compute target time for the next frame
            nextFrameTime = lastTime + targetFrameDurationChrono;
            if (now < nextFrameTime) {
                std::this_thread::sleep_until(nextFrameTime);   // Sleep until next frame if ahead of schedule
                lastTime = nextFrameTime;
                diff = targetFrameDurationChrono;
            }
            else {
                diff = now - lastTime;
                lastTime = now;
            }
        }
        else {  // Max FPS (FPS control disabled)
            diff = now - lastTime;
            lastTime = now;
        }

        // Update lastTime to current time
        deltaTime = diff.count();
        /*----------------------------------------*/

        if (paused) {
            gameDeltaTime = 0.0f;
        }
        else {
            gameDeltaTime = deltaTime * static_cast<float>(gameSpeed);
            gameAccumulatedTime += static_cast<double>(gameDeltaTime);
        }

#ifdef TIMING_USE_FIXED_STEP
        fixedTimeAccumulator += deltaTime;
#endif
    }

    void TimingManager::pause() {
        if (!paused) {
            paused = true;
            Logger::log(LogFileType::Engine, "Game paused", LogLevel::Info, "Timing Manager");
        }
    }

    void TimingManager::resume() {
        if (paused) {
            paused = false;
            Logger::log(LogFileType::Engine, "Game resumed", LogLevel::Info, "Timing Manager");
        }
    }

    bool TimingManager::isPaused() const {
        return paused;
    }

    float TimingManager::getCurrentFPS() const {
        return (deltaTime > 0.0f) ? (1.0f / deltaTime) : 0.0f;
    }

    void TimingManager::setTargetFPS(int fps) {
        targetFPS = fps;
        targetFrameDuration = (fps > 0) ? 1.0 / static_cast<double>(fps) : 0.0;

        if (fps > 0) {
            targetFrameDurationChrono = std::chrono::duration_cast<Clock::duration>(
                std::chrono::duration<double>(targetFrameDuration)
            );
        }
        else {
            targetFrameDurationChrono = Clock::duration::zero();
        }
    }

    int TimingManager::getTargetFPS() const {
        return targetFPS;
    }

    double TimingManager::getTargetFrameDuration() const {
        return targetFrameDuration;
    }

    void TimingManager::setGameSpeed(double speed) {
        if (speed != gameSpeed) {
            gameSpeed = speed;

            std::string message = std::format(
                "[TimingManager] Game speed changed to {:.2f} at {:.3f}s",
                speed, getTotalTime()
            );
            Logger::log(LogFileType::Engine, message, LogLevel::Info, "Timing Manager");
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
        return (Clock::now() - startTime).count();
    }

    double TimingManager::getGameTotalTime() const {
        return gameAccumulatedTime;
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
