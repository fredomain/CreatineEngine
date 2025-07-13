#include "TransitionScene.h"
#include "SceneManager.h"

namespace CE {

    void TransitionScene::setTargetScene(Scene* scene) {
        targetScene = scene;
    }

    void TransitionScene::update() {
        Scene::update();        // Calls base class to update and render
        // Then call the targetScene. This is an static transition screen
        SceneManager::loadScene(targetScene);
    }

}
