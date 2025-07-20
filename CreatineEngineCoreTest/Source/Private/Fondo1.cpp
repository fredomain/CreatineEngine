#include "Fondo1.h"
#include <memory>
#include "ResourceManager.h"
#include <print>

Fondo1::Fondo1(CE::Scene& scene) {

	textureInst = std::make_unique<CE::TextureInstanceRotatable>(
		CE::ResourceManager::getImageTexture(
			"fondo2",
			CE::SceneManager::getWindowRenderer(),
			"Content/background2.png"
		)
	);

	scene.registerComponent(*textureInst);	
}

void Fondo1::initialize() {
	textureInst->setPositionAnchor(CE::RectAnchor::CENTER);
	textureInst->setPosition(CE::SceneManager::getWindowManager().getWidth() / 2, CE::SceneManager::getWindowManager().getHeight() / 2);
	textureInst->setScale(0.2f);

	textureInst->setRotationOrigin(CE::RectAnchor::CENTER);
	textureInst->setRotation(15);
	textureInst->setFlipMode(SDL_FlipMode::SDL_FLIP_VERTICAL);

	CE::Logger::log(CE::LogFileType::Engine, std::format("x: {}, y: {}", textureInst->getX(), textureInst->getY()), CE::LogLevel::Verbose);
}

void Fondo1::update(float deltaTime) {
	Entity::update(deltaTime);
}
