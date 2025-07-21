#include "FPS_Display.h"

FPS_Display::FPS_Display(CE::Scene& scene) {

	textureInst = std::make_unique<CE::TextureInstance>(
		CE::ResourceManager::getTextTexture()
		)
	);

	scene.registerComponent(*textureInst);
}

void FPS_Display::initialize() {


	CE::Logger::log(CE::LogFileType::Engine, std::format("x: {}, y: {}", textureInst->getX(), textureInst->getY()), CE::LogLevel::Verbose);
}

void FPS_Display::update(float deltaTime) {
	Entity::update(deltaTime);
}
