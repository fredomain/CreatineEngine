#include "TransitionScene.h"
#include "SceneManager.h"

namespace CE {

    TransitionScene::TransitionScene(std::string name) : Scene(name) {

    }

    void TransitionScene::setTargetScene(const std::string& sceneName) {
        targetSceneName = sceneName;
    }

    std::string TransitionScene::getTargetSceneName() const {
        return targetSceneName;
    }

    void TransitionScene::loadTargetScene() {
        SceneManager::loadScene(targetSceneName);
        SceneManager::endTransition();
    }

    void TransitionScene::update() {
        // Call base scene update to render background or animations
        Scene::update();

        loadTargetScene();
    }

}
