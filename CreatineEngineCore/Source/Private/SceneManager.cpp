#include "SceneManager.h"

namespace CE {

    bool SceneManager::initializeGraphics(const std::string& title, int width, int height, bool fullscreen) {
        if (!windowManager.initialize(title, width, height, fullscreen)) {
            SDL_Log("Failed to initialize WindowManager");
            return false;
        }
        return true;
    }

    void SceneManager::addScene(const std::string& name, std::unique_ptr<Scene> scene) {
        get().scenes[name] = std::move(scene);
    }

    void SceneManager::setTransitionScene(std::unique_ptr<TransitionScene> scene) {
        get().transitionScene = std::move(scene);
    }

    void SceneManager::loadScene(const std::string& scene) {
        SceneManager& mgr = get();

        if (!mgr.isTransitioning && mgr.currentScene) {
            mgr.currentScene->shutdown();
        }

        auto it = mgr.scenes.find(scene);           // Find the scene for that string key
        if (it != mgr.scenes.end()) {               // Within the unordered map
            mgr.currentScene = it->second.get();    // Get the object for that element and get a raw pointer to it
            mgr.currentScene->initialize();
        }
        else {
            throw std::runtime_error("Scene '" + scene + "' not found");
        }
    }

    void SceneManager::loadScene(Scene* scene) {
        if (scene) {
            SceneManager& mgr = get();

            if (!mgr.isTransitioning && mgr.currentScene) {
                mgr.currentScene->shutdown();
            }

            mgr.currentScene = scene;
            mgr.currentScene->initialize();           
        }
        else {
            throw std::runtime_error("Scene not valid");
        }
        
    }

    void SceneManager::loadSceneWithTransition(const std::string& targetScene) {
        SceneManager& mgr = get();

        if (!mgr.transitionScene) {
            throw std::runtime_error("No transition scene set!");
        }

        mgr.nextScene = mgr.scenes[targetScene].get();
        mgr.transitionScene->setTargetScene(mgr.nextScene);

        mgr.isTransitioning = true;
        mgr.transitionScene.get()->initialize();        // Initialize the transition scene
        mgr.transitionScene.get()->update();            // Update and render it before starting the current scene shutdown
        mgr.currentScene->shutdown();
        mgr.currentScene = mgr.transitionScene.get();   // Set the transition scene as the current scene        
    }

    void SceneManager::update() {
        SceneManager& mgr = get();
        if (mgr.currentScene) {
            mgr.currentScene->update();
        }
    }

    Scene* SceneManager::getCurrentScene() {
        return get().currentScene;
    }

    Scene* SceneManager::getNextScene() {
        if (inTransition()) {     // Next scene only makes sense while in transition
            return get().nextScene;
        }
        else {
            return nullptr;
        }
        
    }

    bool SceneManager::inTransition() {
        return get().isTransitioning;
    }

    WindowManager& SceneManager::getWindowManager() {
        return get().windowManager;
    }

}
