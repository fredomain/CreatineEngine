#pragma once
#ifndef TIMINGMANAGER_H
#define TIMINGMANAGER_H

#include <chrono>
#include <vector>

namespace CE {

    /**
     * @Class Class for time managing, including FPS control, pauses and game speed.
     */
    class TimingManager {
    public:
        TimingManager(double fixedTimeStep = 1.0 / 60.0, int targetFPS = 60);
        void start();
        void reset();
        void update();

        void pause();
        void resume();
        bool isPaused() const;

        float getCurrentFPS() const;

        void setTargetFPS(int fps);
        int getTargetFPS() const;
        double getTargetFrameDuration() const;

        void setGameSpeed(double speed);
        double getGameSpeed() const;

        float getDeltaTime() const;
        float getGameDeltaTime() const;

        double getTotalTime() const;
        double getGameTotalTime() const;

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

        // Preallocated time points and durations for high performance
        TimePoint startTime;
        TimePoint lastTime;
        TimePoint now;
        TimePoint nextFrameTime;
        std::chrono::duration<float> diff = std::chrono::duration<float>::zero();

        // Preconverted target frame duration for efficient updates
        Clock::duration targetFrameDurationChrono;

        bool paused;
        TimePoint pauseStartTime;

        float deltaTime;
        float gameDeltaTime;
        double gameAccumulatedTime;

        int targetFPS;
        double targetFrameDuration;

        double gameSpeed;

#ifdef TIMING_USE_FIXED_STEP
        double fixedTimeStep;
        double fixedTimeAccumulator;
#endif
    };

}

#endif
