#include <print>
#include "CreatineEngineCore.h"

int main()
{
    CE::CreatineEngineCore::init();

    std::print("Hello World!\n");

    // Initialize the game
    //CE::SceneManager::addScene

    // Game loop
    bool working = true;
    while (working) {
        CE::SceneManager::update();
    }

    CE::CreatineEngineCore::quit();
}
