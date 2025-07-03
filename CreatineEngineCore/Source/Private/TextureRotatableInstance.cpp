#include "TextureRotatableInstance.h"
#include "MathConstants.h"

namespace CE {

	TextureRotatableInstance::TextureRotatableInstance(
		SDL_Renderer* renderer,
		SDL_Texture* texture,
		double rotation,
		FVector rotationOrigin,
		SDL_FlipMode flipMode
	) :
		TextureInstance(renderer, texture),
		rotation(rotation),
		rotationOrigin(rotationOrigin),
		flipMode(flipMode) {

	}

	TextureRotatableInstance::TextureRotatableInstance(
		SDL_Renderer* renderer,
		SDL_Surface* surface,
		double rotation,
		FVector rotationOrigin,
		SDL_FlipMode flipMode
	) :
		TextureInstance(renderer, surface),
		rotation(rotation),
		rotationOrigin(rotationOrigin),
		flipMode(flipMode) {

	}

	TextureRotatableInstance::TextureRotatableInstance(
		SDL_Renderer* renderer,
		ImageLoader& imageLoader,
		double rotation,
		FVector rotationOrigin,
		SDL_FlipMode flipMode
	) :

		TextureInstance(renderer, imageLoader),
		rotation(rotation),
		rotationOrigin(rotationOrigin),
		flipMode(flipMode) {

	}

	TextureRotatableInstance::TextureRotatableInstance(
		SDL_Renderer* renderer,
		std::string text,
		TTF_Font* font,
		size_t textSize,
		SDL_Color textColor,
		double rotation,
		FVector rotationOrigin,
		SDL_FlipMode flipMode
	) :
		TextureInstance(renderer, text, font, textSize, textColor),
		rotation(rotation),
		rotationOrigin(rotationOrigin),
		flipMode(flipMode) {

	}

	void TextureRotatableInstance::render() const {

		if (std::abs(getRotation()) > CE::NEAR_ZERO_THRESHOLD) {		// render with rotation
			SDL_FPoint rotationOriginSDL(getRotationOriginSDL());
			SDL_RenderTextureRotated(renderer, data, getSourceRectPtr(), getDestinationRectPtr(), getRotation(), &rotationOriginSDL, getFlipMode());
			//SDL_Log("renderRotated");
		}
		else {
			TextureInstance::render();
		}
	}

	void TextureRotatableInstance::init() {
		TextureInstance::init();

		// Initialize parameters
		rotation = 0.0;
		setRotationOrigin(RectAnchor::CENTER);
	}

	double TextureRotatableInstance::getRotation() const {
		return rotation;
	}

	void TextureRotatableInstance::setRotation(double rotation) {
		this->rotation = rotation;
	}

	void TextureRotatableInstance::setRotationOrigin(float x, float y) {
		rotationOrigin.x = x;
		rotationOrigin.y = y;
		//printf("Rotation origin: %f, %f\n", x, y);
	}

	void TextureRotatableInstance::setRotationOrigin(FVector rotationOrigin) {
		setRotationOrigin(rotationOrigin.x, rotationOrigin.y);
	}

	void TextureRotatableInstance::setRotationOrigin(RectAnchor rotationAnchor) {
		setRotationOrigin(computeAnchorOffset(getWidth(), getHeight(), rotationAnchor));
	}

	float TextureRotatableInstance::getRotationOriginX() const {
		return rotationOrigin.x;
	}

	float TextureRotatableInstance::getRotationOriginY() const {
		return rotationOrigin.y;
	}

	FVector TextureRotatableInstance::getRotationOrigin() const {
		return rotationOrigin;
	}

	SDL_FPoint TextureRotatableInstance::getRotationOriginSDL() const {
		return SDL_FPoint(rotationOrigin.x, rotationOrigin.y);
	}

	void TextureRotatableInstance::setVerticalFlip() {
		flipMode = SDL_FlipMode::SDL_FLIP_VERTICAL;
	}

	void TextureRotatableInstance::setHorizontalFlip() {
		flipMode = SDL_FlipMode::SDL_FLIP_HORIZONTAL;
	}

	void TextureRotatableInstance::disableFlip() {
		flipMode = SDL_FlipMode::SDL_FLIP_NONE;
	}

	void TextureRotatableInstance::setFlipMode(const SDL_FlipMode& mode) {
		flipMode = mode;
	}

	SDL_FlipMode TextureRotatableInstance::getFlipMode() const {
		return flipMode;
	}

	const SDL_FlipMode& TextureRotatableInstance::getFlipModeRef() const {
		return flipMode;
	}
}