#include "LoadingLabel.h"
#include <utility>

LoadingLabel::LoadingLabel(std::string text) {

	SDL_Color color{ 255, 255, 0, 255 };
	font = TTF_OpenFont("Content/Fonts/lazy.ttf", 60);

	textureInst = std::make_unique<CE::TextureInstance>(
		CE::ResourceManager::getTexture<CE::TextTexture>(
			"loadingLabel",
			CE::SceneManager::getWindowRenderer(),
			std::move(text),
			font,
			26,
			color
		)
	);
}

void LoadingLabel::registerComponentsInScene(CE::Scene& scene) {
	scene.registerComponent(*textureInst);
}

void LoadingLabel::initialize() {
}

void LoadingLabel::update(float deltaTime) {
	Entity::update(deltaTime);
}