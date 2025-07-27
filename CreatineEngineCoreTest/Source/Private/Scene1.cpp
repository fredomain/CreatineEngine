#include "Scene1.h"

Scene1::Scene1(std::string name) : Scene(name) {
	fondo = dynamic_cast<Fondo1*>(registerEntity(std::make_unique<Fondo1>()));
}

void Scene1::initialize() {
	Scene::initialize();
	renderEngine.enableClear();
	timingManager.setTargetFPS(100);

	fondo->textureInst->setPositionAnchor(CE::RectAnchor::CENTER);
	fondo->textureInst->setPosition(static_cast<float>(CE::SceneManager::getWindowManager().getWidth()) / 2, static_cast<float>(CE::SceneManager::getWindowManager().getHeight() / 2));
	fondo->textureInst->setScale(0.2f);

	fondo->textureInst->setRotationOrigin(CE::RectAnchor::CENTER);
	fondo->textureInst->setRotation(15);
	fondo->textureInst->setFlipMode(SDL_FlipMode::SDL_FLIP_VERTICAL);

	CE::Logger::log(CE::LogFileType::Engine, std::format("x: {}, y: {}", fondo->textureInst->getX(), fondo->textureInst->getY()), CE::LogLevel::Verbose);
}

void Scene1::update() {
	Scene::update();
	//Handle events on queue
	while (SDL_PollEvent(&e) != 0)
	{
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
				break;
			}
		}
	}
}
