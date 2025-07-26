#include "Fondo1.h"
#include <memory>
#include "ResourceManager.h"
#include <print>

Fondo1::Fondo1() {

	textureInst = std::make_unique<CE::TextureInstanceRotatable>(
		CE::ResourceManager::getImageTexture(
			"fondo2",
			CE::SceneManager::getWindowRenderer(),
			"Content/background2.png"
		)
	);
}

void Fondo1::registerComponentsInScene(CE::Scene& scene) {
	scene.registerComponent(*textureInst);
}

void Fondo1::initialize() {
}

void Fondo1::update(float deltaTime) {
	Entity::update(deltaTime);
}