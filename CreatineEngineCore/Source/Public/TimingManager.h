#pragma once
#ifndef TIMINGMANAGER_H
#define TIMINGMANAGER_H

#include <chrono>
#include <vector>

namespace CE {

     /**
     * @Class Class for time managing, including FPS control, pauses y and game speed.
     * @Param fixedTimeStep The fixed time step for updates, default is 1/60 seconds.
     * @Param DeltaTime The time between frames in seconds.
     * @Param DeltaGameTime The time between frames in game time, considering game speed.
     * @Param accumulatedTime The total real time elapsed since the start.
	 * @Param gameAccumulatedTime The total game time elapsed since the start, considering game speed.
	 * @param targetFPS The target frames per second for the application.
	 * @param targetFrameDuration The duration of each frame in seconds, calculated from targetFPS.
     *
     **/
    class TimingManager {
    public:
        /**
         * @brief Constructs a TimingManager object to manage timing and frame rate control for a game or simulation.
         * @param fixedTimeStep The fixed time step duration (in seconds) used for fixed-step updates. Only used if TIMING_USE_FIXED_STEP is defined.
         * @param targetFPS The desired target frames per second for the application. If set to a value greater than 0, the target frame duration is calculated accordingly.
         */
        TimingManager(double fixedTimeStep = 1.0 / 60.0, int targetFPS = 60);
        /**
         * @brief Initializes and starts the timing manager, resetting all timing variables and state.
         */
        void start();
        /**
		 * @brief Resets the timing manager to its initial state, calling start function
         */
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

		float getDeltaTime() const;       // Real time between frames in seconds
		float getGameDeltaTime() const;   // Game time between frames, considering game speed

        double getTotalTime() const;      // Accumulated Real Time
        double getGameTime() const;       // Accumulated GameTime

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
