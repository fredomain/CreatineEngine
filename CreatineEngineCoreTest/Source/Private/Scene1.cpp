#include "Scene1.h"
#include "Fondo1.h"

Scene1::Scene1() {
	registerEntity(std::make_unique<Fondo1>(*this));
}

void Scene1::initialize() {
	Scene::initialize();
	renderEngine.enableClear();
	renderEngine.setClearColor(0, 0, 0, 255);
	timingManager.setTargetFPS(100);
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
	}
}
