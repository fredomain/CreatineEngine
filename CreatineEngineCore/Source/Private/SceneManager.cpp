#include "SceneManager.h"
#include "ResourceManager.h"

namespace CE {

    SceneManager::~SceneManager() {
        shutdown();
    }

    void SceneManager::shutdown() {
        SceneManager& mgr = get();
        mgr.sceneDescriptors.clear();           // Destructors will be called
        mgr.currentScene.reset();
        mgr.transitionScene.reset();   

        mgr.windowManager.shutdown();
    }

    bool SceneManager::initializeWindow(const std::string& title, int width, int height, bool fullscreen) {
        SceneManager& mgr = get();
        if (!mgr.windowManager.initialize(title, width, height, fullscreen)) {
            SDL_Log("Failed to initialize WindowManager");
            return false;
        }
        return true;
    }

    void SceneManager::registerScene(const std::string& name, std::function<std::unique_ptr<Scene>()> sceneDescription) {
        get().sceneDescriptors[name] = std::move(sceneDescription);
    }

    void SceneManager::setTransitionScene(std::shared_ptr<TransitionScene> scene) {
        get().transitionScene = std::move(scene);
    }

    void SceneManager::loadScene(const std::string& name) {
        SceneManager& mgr = get();

        auto it = mgr.sceneDescriptors.find(name);
        if (it == mgr.sceneDescriptors.end()) {
            throw std::runtime_error("Scene '" + name + "' not found");
        }

        // Build and initialize the new scene (last scene object will be destroyed)
        mgr.currentScene = it->second();    // Here resources of this new scene are registered (first, it->second() is executed, and then assigned to currentScene, 
                                            // deleting the old scene object
                                            // So then, last scene is gone, with its resources
                                            // This happens because the std::unique_ptr<Scene> currentScene stops poiting to the last scene,
                                            // so the object is deleted
        ResourceManager::clearUnused();     // Clear registered resources from the last scene but not used in the new loaded scene 
        ResourceManager::load();            // Then load registered resources
        mgr.currentScene->initialize();     // With resources loaded, entities can be initialized
    }

    void SceneManager::loadSceneWithTransition(const std::string& targetScene) {
        SceneManager& mgr = get();

        if (!mgr.transitionScene) {
            throw std::runtime_error("No transition scene set!");
        }

        mgr.isTransitioning = true;
        mgr.nextSceneName = targetScene;

        // Initialize and activate transition scene
        mgr.transitionScene->setTargetScene(targetScene);
        mgr.transitionScene->initialize();
        //mgr.transitionScene->update();
        
        mgr.currentScene = mgr.transitionScene; // Here the last scene is destroyed
                                                // (if currentScene is the only owner of it,
                                                // which must be the case here)
    }

    void SceneManager::update() {
        SceneManager& mgr = get();
        if (mgr.currentScene) {
            mgr.currentScene->update();
        }
    }

    Scene* SceneManager::getCurrentScene() {
        return get().currentScene.get();
    }

    std::string SceneManager::getNextSceneName() {
        return get().nextSceneName;
        
    }

    bool SceneManager::inTransition(){
        return get().isTransitioning;
    }

    void SceneManager::endTransition() {
        get().isTransitioning = false;
    }

    WindowManager& SceneManager::getWindowManager() {
        return get().windowManager;
    }

    SDL_Renderer* SceneManager::getWindowRenderer() {
        return get().windowManager.getRenderer();
    }
}
