#include "Timer.h"

#include <SDL3/SDL.h>

namespace CE {

    Timer::Timer()
    {
        // Initialize the variables
        startTicks = 0;
        pausedTicks = 0;

        paused = false;
        started = false;
    }

    void Timer::start()
    {
        // Get the current clock time
        startTicks = SDL_GetTicks();
        pausedTicks = 0;

        // Start the timer
        started = true;

        // Unpause the timer
        paused = false;
    }

    void Timer::stop()
    {
        // Clear tick variables
        startTicks = 0;
        pausedTicks = 0;

        // Stop the timer
        started = false;

        // Unpause the timer
        paused = false;        
    }

    void Timer::pause()
    {
        // If the timer is running and isn't already paused
        if (started && !paused)
        {
            // Calculate the paused ticks
			pausedTicks = SDL_GetTicks() - startTicks;  // Ticks since the timer started
            startTicks = 0;

            // Pause the timer
            paused = true;
        }
    }

    void Timer::unpause()
    {
        // If the timer is running and paused
        if (started && paused)
        {
            // Reset the starting ticks
            startTicks = SDL_GetTicks() - pausedTicks;

            // Reset the paused ticks
            pausedTicks = 0;

            // Unpause the timer
            paused = false;
        }
    }

    uint32_t Timer::getTicks() const{
        // If the timer is running
        if (started)
        {
            // If the timer is paused
            if (paused){
                // Return the number of ticks when the timer was paused
                // It is actually the timer time
                return pausedTicks;
            }
            else{
                //Return the current time minus the start time
                return (SDL_GetTicks() - startTicks);
            }
        }
    }

    bool Timer::isStarted() const {
        // Timer is running and paused or unpaused
        return started;
    }

    bool Timer::isPaused() const {
        // Timer is running and paused
        return paused && started;
    }

}