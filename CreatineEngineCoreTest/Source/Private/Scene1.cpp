#include "Scene1.h"
#include "Fondo1.h"

Scene1::Scene1() {
	registerEntity(std::make_unique<Fondo1>(*this));
}

void Scene1::initialize() {
	Scene::initialize();
	renderEngine.enableClear();
	renderEngine.setClearColor(0, 0, 0, 255);
}
