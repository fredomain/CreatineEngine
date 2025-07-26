#include "SimpleTransitionScene.h"
#include <thread>

SimpleTransitionScene::SimpleTransitionScene() {
    loadingLabel = new LoadingLabel();
    registerEntity(static_cast<std::unique_ptr<LoadingLabel>>(loadingLabel));
}

void SimpleTransitionScene::initialize() {
    loadingLabel->textureInst->setY(CE::SceneManager::getWindowManager().getHeight() - loadingLabel->textureInst->getHeight());
}

void SimpleTransitionScene::update() {
    // Call base scene update to render background or animations
    Scene::update();

    std::this_thread::sleep_for(std::chrono::seconds(1));
    loadTargetScene();
}
