#include "SimpleTransitionScene.h"
#include <thread>

SimpleTransitionScene::SimpleTransitionScene(std::string name) : TransitionScene(name) {
    loadingLabel = dynamic_cast<LoadingLabel*>(registerEntity(std::make_unique<LoadingLabel>()));
}

void SimpleTransitionScene::initialize() {
    Scene::initialize();
    loadingLabel->textureInst->setY(CE::SceneManager::getWindowManager().getHeight() - loadingLabel->textureInst->getHeight());
}

void SimpleTransitionScene::update() {
    // Call base scene update to render background or animations
    Scene::update();

    std::this_thread::sleep_for(std::chrono::seconds(1));
    loadTargetScene();
}
