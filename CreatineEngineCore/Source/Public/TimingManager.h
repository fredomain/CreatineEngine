#pragma once
#ifndef TIMINGMANAGER_H
#define TIMINGMANAGER_H

#include <chrono>
#include <vector>

namespace CE {

    class TimingManager {
    public:
        TimingManager(double fixedTimeStep = 1.0 / 60.0, int targetFPS = 60);

        void start();
        void reset();
        void update();

        void pause();
        void resume();
        bool isPaused() const;

        void frameRateControl();
        float getCurrentFPS() const;

        void setTargetFPS(int fps);
        int getTargetFPS() const;
        double getTargetFrameDuration() const;

        void setGameSpeed(double speed);
        double getGameSpeed() const;

        float getDeltaTime() const;       // Tiempo real entre frames
        float getGameDeltaTime() const;   // Tiempo de juego entre frames

        double getTotalTime() const;      // Tiempo real acumulado
        double getGameTime() const;       // Tiempo de juego acumulado

        double getTimeDrift() const;
        void correctDrift();

#ifdef TIMING_USE_FIXED_STEP
        bool shouldStepFixedUpdate();
        double getFixedTimeStep() const;
#endif

    private:
        using Clock = std::chrono::steady_clock;
        using TimePoint = Clock::time_point;

        struct SpeedChange {
            double speed;
            double timeAtChange;
        };

        TimePoint startTime;
        TimePoint lastTime;
        bool paused;
        TimePoint pauseStartTime;

        float deltaTime;
        float gameDeltaTime;
        double accumulatedTime;
        double gameAccumulatedTime;

        int targetFPS;
        double targetFrameDuration;

        double gameSpeed;
        std::vector<SpeedChange> speedHistory;

#ifdef TIMING_USE_FIXED_STEP
        double fixedTimeStep;
        double fixedTimeAccumulator;
#endif
    };

}

#endif
