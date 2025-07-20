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

    /**** Forma 5 ***/
    /*//CE::ImageTexture imagenFondoT(gRenderer, "Content/Images/background.jpg");
    CE::TextureInstanceRotatable imagenFondo(CE::ResourceManager::getImageTexture("fondo", CE::SceneManager::getWindowRenderer(), "Content/background.jpg"));
    CE::TextureInstanceRotatable imagenFondo2(CE::ResourceManager::getImageTexture("fondo", CE::SceneManager::getWindowRenderer(), "Content/background.jpg"));
    Fondo1 fondo1(*CE::SceneManager::getCurrentScene());
    //std::print("Cargados: {}\n", assetLoaderManager.getLoadedCount());
    CE::ResourceManager::load();
    //std::print("Cargados: {}\n", assetLoaderManager.getLoadedCount());


    imagenFondo.setPositionAnchor(CE::RectAnchor::CENTER);
    imagenFondo.setPosition(CE::SceneManager::getWindowManager().getWidth() / 2, CE::SceneManager::getWindowManager().getHeight() / 2);
    imagenFondo.setScale(0.5f);

    imagenFondo.setRotationOrigin(CE::RectAnchor::CENTER);
    imagenFondo.setRotation(45);
    imagenFondo.setFlipMode(SDL_FlipMode::SDL_FLIP_VERTICAL);

    imagenFondo2.setPositionAnchor(CE::RectAnchor::CENTER);

    imagenFondo2.setPosition(CE::SceneManager::getWindowManager().getWidth() / 4, CE::SceneManager::getWindowManager().getHeight() / 4);
    imagenFondo2.setScale(0.2f);

    imagenFondo2.setRotationOrigin(CE::RectAnchor::CENTER);
    imagenFondo2.setRotation(25);
    imagenFondo2.setFlipMode(SDL_FlipMode::SDL_FLIP_HORIZONTAL);

    fondo1.initialize();*/

    /*SDL_RenderClear(CE::SceneManager::getWindowRenderer());
    imagenFondo.render();
    imagenFondo2.render();
    SDL_RenderPresent(CE::SceneManager::getWindowRenderer());*/

    /**** Forma 5 ***/

    CE::SceneManager::update();
    //CE::SceneManager::getCurrentScene()->initialize();
    //CE::SceneManager::getCurrentScene()->update();
    //CE::Logger::log(CE::LogFileType::Engine, "Update done", CE::LogLevel::Verbose);
    // Game loop
    /*bool working = true;
    while (working) {
        CE::SceneManager::update();
    }*/

    /*SDL_RenderClear(CE::SceneManager::getWindowRenderer());
    imagenFondo.render();
    imagenFondo2.render();
    fondo1.textureInst->render();
    SDL_RenderPresent(CE::SceneManager::getWindowRenderer());*/

    getchar();

    CE::CreatineEngineCore::quit();
}