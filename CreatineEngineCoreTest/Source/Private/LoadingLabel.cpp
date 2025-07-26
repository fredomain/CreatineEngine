#include "LoadingLabel.h"

LoadingLabel::LoadingLabel() {

	SDL_Color color{ 255, 255, 0, 255 };
	font = TTF_OpenFont("Content/Fonts/lazy.ttf", 60);

	textureInst = std::make_unique<CE::TextureInstance>(
		CE::ResourceManager::getTextTexture(
			"loadingLabel",
			CE::SceneManager::getWindowRenderer(),
			"Cagando..",
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