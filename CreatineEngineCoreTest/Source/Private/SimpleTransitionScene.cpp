#include "SimpleTransitionScene.h"
#include <thread>

SimpleTransitionScene::SimpleTransitionScene(std::string name) : TransitionScene(name) {
    loadingLabel = dynamic_cast<LoadingLabel*>(registerEntity(std::make_unique<LoadingLabel>()));
}

void SimpleTransitionScene::initialize() {
    Scene::initialize();
    timingManager.setTargetFPS(2);
    loadingLabel->textureInst->rect.setY(CE::SceneManager::getWindowManager().getHeight() - loadingLabel->textureInst->rect.getHeight());
}

void SimpleTransitionScene::update() {
    // Call base scene update to render background or animations
    Scene::update();

    CE::Logger::log(CE::LogFileType::Engine, std::format("Sleep before loading scene {}", getTargetSceneName()), CE::LogLevel::Warn);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    loadTargetScene();
}
