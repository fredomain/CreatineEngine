#include "TimingManager.h"

namespace CE {

    TimingManager::TimingManager(double fixedTimeStep)
        : deltaTime(0.0f), accumulatedTime(0.0)
#ifdef TIMING_USE_FIXED_STEP
        , fixedTimeStep(fixedTimeStep), fixedTimeAccumulator(0.0)
#endif
    {
    }

    void TimingManager::start() {
        startTime = Clock::now();
        lastTime = startTime;
        deltaTime = 0.0f;
        accumulatedTime = 0.0;
#ifdef TIMING_USE_FIXED_STEP
        fixedTimeAccumulator = 0.0;
#endif
    }

    void TimingManager::update() {
        TimePoint now = Clock::now();
        std::chrono::duration<float> diff = now - lastTime;
        deltaTime = diff.count();
        accumulatedTime += static_cast<double>(deltaTime);
        lastTime = now;
#ifdef TIMING_USE_FIXED_STEP
        fixedTimeAccumulator += deltaTime;
#endif
    }

    float TimingManager::getDeltaTime() const {
        return deltaTime;
    }

    double TimingManager::getTotalTime() const {
        return accumulatedTime;
    }

    double TimingManager::getTimeDrift() const {
        auto now = Clock::now();
        std::chrono::duration<double> realElapsed = now - startTime;
        return accumulatedTime - realElapsed.count();
    }

    void TimingManager::correctDrift() {
        auto now = Clock::now();
        std::chrono::duration<double> realElapsed = now - startTime;
        accumulatedTime = realElapsed.count();
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
