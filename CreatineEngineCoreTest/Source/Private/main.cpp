#include <print>
#include "CreatineEngineCore.h"

#include "Scene1.h"
#include "Scene2.h"
#include "SimpleTransitionScene.h"

#include "Fondo1.h"

int main()
{
    CE::CreatineEngineCore::init();

    std::print("Hello World!\n");

    // Initialize the game
    CE::SceneManager::initializeWindow("Creatine Engine Core Test", 640, 480, false);
    //SDL_SetRenderDrawColor(CE::SceneManager::getWindowRenderer(), 0x00, 0x00, 0x00, 0xFF);
    
    // Add scenes and load one
    CE::SceneManager::registerScene("Scene1", [] {
        return std::make_unique<Scene1>();
        });
    CE::SceneManager::registerScene("Scene2", [] {
        return std::make_unique<Scene2>();
        });

    CE::SceneManager::setTransitionScene(std::make_unique<SimpleTransitionScene>());
    CE::SceneManager::loadScene("Scene1");

    // Game loop
    bool working = true;
    while (working) {
        CE::SceneManager::update();
    }

    getchar();

    CE::CreatineEngineCore::quit();
}