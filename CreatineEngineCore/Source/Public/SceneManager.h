#pragma once
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <unordered_map>
#include <string>
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
        std::unordered_map<std::string, std::unique_ptr<Scene>> scenes;
        Scene* currentScene = nullptr;
        Scene* nextScene = nullptr;
        std::unique_ptr<TransitionScene> transitionScene = nullptr;
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

        static void addScene(const std::string& name, std::unique_ptr<Scene> scene);
        static void setTransitionScene(std::unique_ptr<TransitionScene> scene);

        static void loadScene(const std::string& name);
        static void loadScene(Scene* scene);
        static void loadSceneWithTransition(const std::string& targetScene);

        static void update();

        static Scene* getCurrentScene();
        static Scene* getNextScene();
        static bool inTransition();

        static WindowManager& getWindowManager();
        static SDL_Renderer* getWindowRenderer();

        static void shutdown();
    };

}

#endif
