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

        // Prohibir copiar y mover
        SceneManager(const SceneManager&) = delete;
        SceneManager& operator=(const SceneManager&) = delete;
        SceneManager(SceneManager&&) = delete;
        SceneManager& operator=(SceneManager&&) = delete;

        // Inicialización del sistema gráfico
        bool initializeGraphics(const std::string& title, int width, int height, bool fullscreen = false);

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
    };

}

#endif
