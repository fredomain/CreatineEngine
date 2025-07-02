// TimingManager.h
#pragma once
#ifndef TIMINGMANAGER_H
#define TIMINGMANAGER_H

#include <chrono>
#include <cmath>

// Uncomment or define this in build flags to enable fixed timestep
// Use fixed time for physics (collisions for example)
//#define TIMING_USE_FIXED_STEP

namespace CE {

    class TimingManager {
    public:
        TimingManager(double fixedTimeStep = 1.0 / 60.0);   // Ignore the argument if TIMING_USE_FIXED_STEP is not defined

        void start();
        void update();

        float getDeltaTime() const;
        double getTotalTime() const;
        double getTimeDrift() const;
        void correctDrift();

#ifdef TIMING_USE_FIXED_STEP
        bool shouldStepFixedUpdate();
        double getFixedTimeStep() const;
#endif

    private:
        using Clock = std::chrono::steady_clock;
        using TimePoint = Clock::time_point;

        TimePoint startTime;
        TimePoint lastTime;
        float deltaTime;
        double accumulatedTime;

#ifdef TIMING_USE_FIXED_STEP
        double fixedTimeStep;
        double fixedTimeAccumulator;
#endif
    };

}

#endif // TIMINGMANAGER_H
