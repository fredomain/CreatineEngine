#pragma once
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <unordered_map>
#include <string>
#include <functional>
#include <memory>
#include "Scene.h"
#include "WindowManager.h"
#include "TransitionScene.h"

namespace CE {

    /**
     * @brief Manages scenes and transitions within an application, providing methods for scene control, window management, and rendering.
     */
    class SceneManager {
    private:
        std::unordered_map<std::string, std::function<std::unique_ptr<Scene>()>> sceneDescriptors;
        std::unique_ptr<Scene> currentScene = nullptr;
        std::unique_ptr<TransitionScene> transitionScene = nullptr;
        std::string nextSceneName = "";
        bool isTransitioning = false;

        WindowManager windowManager;

        SceneManager() = default;

    public:
        static SceneManager& get() {
            static SceneManager instance;
            return instance;
        }

        // Destructor
        ~SceneManager();

        // Prohibir copiar y mover
        SceneManager(const SceneManager&) = delete;
        SceneManager& operator=(const SceneManager&) = delete;
        SceneManager(SceneManager&&) = delete;
        SceneManager& operator=(SceneManager&&) = delete;

        static bool initializeWindow(const std::string& title, int width, int height, bool fullscreen = false);

        static void registerScene(const std::string& name, std::function<std::unique_ptr<Scene>()> sceneDescription);
        static void setTransitionScene(std::unique_ptr<TransitionScene> scene);

        static void loadScene(const std::string& name);        
        static void loadSceneWithTransition(const std::string& targetScene);

        static void update();

        static Scene* getCurrentScene();
        static std::string getNextSceneName();
        static bool inTransition();
        static void endTransition();

        static WindowManager& getWindowManager();
        static SDL_Renderer* getWindowRenderer();

        static void shutdown();
    };

}

#endif
