#include <print>
#include "CreatineEngineCore.h"

#include "Scene1.h"
#include "Scene2.h"
#include "SimpleTransitionScene.h"

int main()
{
    CE::CreatineEngineCore::init();

    // Initialize the game
    CE::SceneManager::initializeWindow("Creatine Engine Core Test", 640, 480, false);
    
    // Add scenes and load one
    CE::SceneManager::registerScene("Scene1", [] {
        return std::make_unique<Scene1>("Scene1");
        });
    CE::SceneManager::registerScene("Scene2", [] {
        return std::make_unique<Scene2>("Scene2");
        });

    CE::SceneManager::setTransitionScene(std::make_shared<SimpleTransitionScene>("SimpleTransitionScene"));
    CE::SceneManager::loadScene("Scene1");

    // Game loop
    bool working = true;
    while (working) {
        CE::SceneManager::update();
    }

    CE::CreatineEngineCore::quit();
}