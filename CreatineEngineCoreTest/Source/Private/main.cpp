#include <print>
#include "CreatineEngineCore.h"

#include "Scene1.h"
#include "Scene2.h"
#include "SimpleTransitionScene.h"

#include "Fondo1.h"

#include <print>

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
    uint32_t i = 0;
    float accumulatedDeltaTime = 0.0f;
    auto start = std::chrono::high_resolution_clock::now();
    while (working) {
        CE::SceneManager::update();
        accumulatedDeltaTime += CE::SceneManager::getCurrentScene()->getTimingManager().getDeltaTime();
        if (i > 999) {
            //std::println("{}", static_cast<unsigned int>(CE::SceneManager::getCurrentScene()->getTimingManager().getCurrentFPS()));
            std::chrono::duration<double, std::milli> duration = std::chrono::high_resolution_clock::now() - start;
            start = std::chrono::high_resolution_clock::now();
            std::println("{}, {}", duration, accumulatedDeltaTime/1000);
            accumulatedDeltaTime = 0.0;
            i = 0;            
        }
        i++;
        //std::println("{}", i);
    }

    CE::CreatineEngineCore::quit();
}