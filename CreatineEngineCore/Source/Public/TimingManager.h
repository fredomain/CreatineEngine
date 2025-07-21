#pragma once
#ifndef TIMINGMANAGER_H
#define TIMINGMANAGER_H

#include <chrono>
#include <vector>

namespace CE {

     /**
     * @Class Class for time managing, including FPS control, pauses y and game speed. 
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
		/**
		 * @brief Updates the timing manager, calculating the delta time, game delta time, and accumulating real and game time.
		 * This function should be called once per frame.
		 */
        void update();
		/**
		 * @brief Pauses the timing manager, stopping the accumulation of game time and delta time.
		 * The game delta time will be set to zero while paused.
		 */
        void pause();
        /**
		 * @brief Resumes the timing manager from a paused state, allowing the accumulation of game time and delta time to continue.
         */
        void resume();
        /**
		 * @brief Checks if the timing manager is currently paused.
		 * @return True if the timing manager is paused, false otherwise.
         */
        bool isPaused() const;
		/**
		* @brief Controls the frame rate by sleeping the thread if necessary to maintain the target FPS.
		* This function should be called at the end of each frame to ensure consistent frame timing.
		* @remark This function is only effective if a target FPS is set (greater than 0).
		*/
        void frameRateControl();
        /**
		 * @brief Gets the current frames per second based on the last frame's delta time.
		 * @return The current frames per second, calculated as 1.0 / deltaTime.
         */
        float getCurrentFPS() const;
		/**
		 * @brief Sets the target frames per second for the application.
		 * @param fps The desired target frames per second. If set to a value greater than 0, the target frame duration is calculated accordingly.
		 */
        void setTargetFPS(int fps);
        /**
		 * @brief Gets the target frames per second for the application.
		 * @return The target frames per second, or 0 if not set.
         */
        int getTargetFPS() const;
        /**
		 * @brief Gets the target frame duration in seconds based on the target FPS.
		 * @return The target frame duration in seconds, calculated as 1.0 / targetFPS.
         */
        double getTargetFrameDuration() const;
		/**
		 * @brief Sets the fixed time step for updates.
		 * @param fixedTimeStep The fixed time step duration in seconds. Only used if TIMING_USE_FIXED_STEP is defined.
		 */
        void setGameSpeed(double speed);
        /**
		 * @brief Gets the current game speed multiplier.
		 * @return The current game speed multiplier, where 1.0 is normal speed, 2.0 is double speed, etc.
         */
        double getGameSpeed() const;

        float getDeltaTime() const;       // Real time between frames in seconds
        float getGameDeltaTime() const;   // Game time between frames, considering game speed

        double getTotalTime() const;      // Accumulated Real Time
        double getGameTime() const;       // Accumulated GameTime

        double getTimeDrift() const;
		/**
		 * @brief Corrects the time drift by adjusting the accumulated game time based on the real elapsed time.
		 * This function should be called periodically to ensure that the game time remains in sync with the real time.
		 */
        void correctDrift();



#ifdef TIMING_USE_FIXED_STEP
        bool shouldStepFixedUpdate();
        double getFixedTimeStep() const;
#endif

    private:
        using Clock = std::chrono::steady_clock;
        using TimePoint = Clock::time_point;

		struct SpeedChange {        // Represents a change in game speed at a specific time
            double speed;
            double timeAtChange;
        };

        TimePoint startTime;
        TimePoint lastTime;
        bool paused;
        TimePoint pauseStartTime;

        float deltaTime;            // Real time between frames in seconds
		float gameDeltaTime;        // Game time between frames, considering game speed    
		double accumulatedTime;     // Accumulates the real time in seconds
		double gameAccumulatedTime; // Accumulates the game time in seconds, considering game speed

		int targetFPS;              // Target frames per second for the application
		double targetFrameDuration; // Duration of each frame in seconds, calculated from targetFPS

		double gameSpeed;           // The current game speed multiplier, default is 1.0 (normal speed)
        std::vector<SpeedChange> speedHistory;

#ifdef TIMING_USE_FIXED_STEP
        double fixedTimeStep;       // The fixed time step for updates, default is 1/60 seconds.
		double fixedTimeAccumulator;// Accumulates the real time for fixed step updates
#endif
    };

}

#endif
