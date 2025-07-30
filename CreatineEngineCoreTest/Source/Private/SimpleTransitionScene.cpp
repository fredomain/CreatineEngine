#include "SimpleTransitionScene.h"
#include <thread>

SimpleTransitionScene::SimpleTransitionScene(std::string name) : TransitionScene(name) {
    loadingLabel = dynamic_cast<LoadingLabel*>(registerEntity(std::make_unique<LoadingLabel>()));
}

void SimpleTransitionScene::initialize() {
    Scene::initialize();
    renderEngine.setClearColor(255, 0, 0, 255);
    timingManager.setTargetFPS(0);
    loadingLabel->textureInst->rect.setY(CE::SceneManager::getWindowManager().getHeight() - loadingLabel->textureInst->rect.getHeight());
}

void SimpleTransitionScene::update() {
    CE::Logger::log(CE::LogFileType::Engine, "TransitionScene is being updated (including rendered)", CE::LogLevel::Debug);
    // Call base scene update to render background or animations
    Scene::update();

    CE::Logger::log(CE::LogFileType::Engine, std::format("Sleep before loading scene {}", getTargetSceneName()), CE::LogLevel::Warn);
    //render();
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    int variable = 10;
    for (int i = 0; i < 200000000; i++) {
        variable *= variable;
    }
    loadTargetScene();
}
