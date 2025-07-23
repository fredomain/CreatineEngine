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

#ifdef TIMING_USE_FIXED_STEP
        fixedTimeAccumulator = 0.0;
#endif
    }

    void TimingManager::reset() {
        start();
    }

    void TimingManager::update() {
        now = Clock::now(); // Captura el tiempo actual

        // Calcula el tiempo transcurrido desde el último frame
        diff = now - lastTime;

        // Si tienes FPS objetivo, calcula el siguiente timestamp absoluto
        if (targetFPS > 0) {
            // Calcula el instante objetivo del próximo frame
            lastTime += std::chrono::duration_cast<Clock::duration>(
                std::chrono::duration<double>(targetFrameDuration)
            );


            // Si estamos adelantados, dormimos hasta el instante objetivo
            if (now < lastTime) {
                std::this_thread::sleep_until(lastTime);
                now = Clock::now(); // Vuelve a capturar el tiempo real después del sleep
            }
            else {
                // Si estamos retrasados, sincronizamos para evitar acumulación de error
                lastTime = now;
                diff = std::chrono::duration<float>::zero(); // No queremos avanzar tiempo de juego extra
            }
        }
        else {
            // Si no hay límite de FPS, sincroniza timestamp
            lastTime = now;
        }

        // Actualiza deltaTime (tiempo real entre frames en segundos)
        deltaTime = diff.count();
        accumulatedTime += static_cast<double>(deltaTime);

        // Actualiza el tiempo de juego, teniendo en cuenta la pausa y la velocidad
        if (paused) {
            gameDeltaTime = 0.0f;
        }
        else {
            gameDeltaTime = deltaTime * static_cast<float>(gameSpeed);
            gameAccumulatedTime += static_cast<double>(gameDeltaTime);
        }

#ifdef TIMING_USE_FIXED_STEP
        fixedTimeAccumulator += deltaTime; // Acumula tiempo para lógica de paso fijo
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
                speed, accumulatedTime
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
        return accumulatedTime;
    }

    double TimingManager::getGameTime() const {
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
