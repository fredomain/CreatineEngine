#pragma once
#ifndef TRANSITIONSCENE_H
#define TRANSITIONSCENE_H

#include "Scene.h"
#include <string>

namespace CE {

    /**
     * @brief Special scene used for transitions between two regular scenes.
     * Can display animations, progress bars, or static screens during the load.
     */
    class TransitionScene : public Scene {
    private:
        std::string targetSceneName;

    public:
        TransitionScene() = default;

        /**
         * @brief Sets the name of the target scene to load after this transition.
         * @param sceneName The unique name of the scene previously registered in SceneManager.
         */
        void setTargetScene(const std::string& sceneName);

        /**
         * @brief Updates and renders the transition screen. Loads the target scene when done.
         */
        void update() override;
    };

}

#endif // TRANSITIONSCENE_H
