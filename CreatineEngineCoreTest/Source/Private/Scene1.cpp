#include "Scene1.h"

Scene1::Scene1(std::string name) : Scene(name) {
	fondo = createEntity<Fondo1>();
}

void Scene1::initialize() {
	Scene::initialize();
	renderEngine.enableClear();
	//timingManager.setTargetFPS(0);

	fondo->textureInst->rect.setAnchor(CE::RectAnchor::CENTER);
	fondo->textureInst->rect.setPosition(static_cast<float>(CE::SceneManager::getWindowManager().getWidth()) / 2, static_cast<float>(CE::SceneManager::getWindowManager().getHeight() / 2));
	fondo->textureInst->setScale(0.2f);

	//fondo->textureInst->setRotationOrigin(CE::RectAnchor::CENTER);
	//fondo->textureInst->setRotation(15);
	//fondo->textureInst->setFlipMode(SDL_FlipMode::SDL_FLIP_VERTICAL);

	//CE::Logger::log(CE::LogFileType::Engine, std::format("x: {}, y: {}", fondo->textureInst->rect.getX(), fondo->textureInst->rect.getY()), CE::LogLevel::Verbose);
}

void Scene1::update() {
	Scene::update();
	//Handle events on queue
	bool clear_events = false;
	while (SDL_PollEvent(&e) != 0)
	{
		if (clear_events == false) {
			//User requests quit
			if (e.type == SDL_EVENT_QUIT)
			{
				std::println("Esto deberia salirse!!!");
			}
			else if (e.type == SDL_EVENT_KEY_DOWN) {
				//Select surfaces based on key press
				switch (e.key.key)
				{
				case SDLK_1:
					CE::SceneManager::loadSceneWithTransition("Scene2");
					clear_events = true;
					break;
				}
			}
		}
	}
}
