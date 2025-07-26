#include "TransitionScene.h"
#include "SceneManager.h"

namespace CE {

    void TransitionScene::setTargetScene(const std::string& sceneName) {
        targetSceneName = sceneName;
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
