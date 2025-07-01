#include "TextureRotatable.h"
#include "MathConstants.h"

namespace CE {

	TextureRotatable::TextureRotatable(
		SDL_Renderer* renderer,
		SDL_Texture* texture,
		double rotation,
		FVector rotationOrigin,
		SDL_FlipMode flipMode
	) :
		Texture(renderer, texture),
		rotation(rotation),
		rotationOrigin(rotationOrigin),
		flipMode(flipMode) {

	}

	TextureRotatable::TextureRotatable(
		SDL_Renderer* renderer,
		SDL_Surface* surface,
		double rotation,
		FVector rotationOrigin,
		SDL_FlipMode flipMode
	) :
		Texture(renderer, surface),
		rotation(rotation),
		rotationOrigin(rotationOrigin),
		flipMode(flipMode) {

	}

	TextureRotatable::TextureRotatable(
		SDL_Renderer* renderer,
		ImageLoader& imageLoader,
		double rotation,
		FVector rotationOrigin,
		SDL_FlipMode flipMode
	) :

		Texture(renderer, imageLoader),
		rotation(rotation),
		rotationOrigin(rotationOrigin),
		flipMode(flipMode) {

	}

	TextureRotatable::TextureRotatable(
		SDL_Renderer* renderer,
		std::string text,
		TTF_Font* font,
		size_t textSize,
		SDL_Color textColor,
		double rotation,
		FVector rotationOrigin,
		SDL_FlipMode flipMode
	) :
		Texture(renderer, text, font, textSize, textColor),
		rotation(rotation),
		rotationOrigin(rotationOrigin),
		flipMode(flipMode) {

	}

	void TextureRotatable::render() const {

		if (std::abs(getRotation()) > CE::NEAR_ZERO_THRESHOLD) {		// render with rotation
			SDL_FPoint rotationOriginSDL(getRotationOriginSDL());
			SDL_RenderTextureRotated(renderer, data, getSourceRectPtr(), getDestinationRectPtr(), getRotation(), &rotationOriginSDL, getFlipMode());
			//SDL_Log("renderRotated");
		}
		else {
			Texture::render();
		}
	}

	void TextureRotatable::init() {
		Texture::init();

		// Initialize parameters
		rotation = 0.0;
		setRotationOrigin(RectAnchor::CENTER);
	}

	double TextureRotatable::getRotation() const {
		return rotation;
	}

	void TextureRotatable::setRotation(double rotation) {
		this->rotation = rotation;
	}

	void TextureRotatable::setRotationOrigin(float x, float y) {
		rotationOrigin.x = x;
		rotationOrigin.y = y;
		printf("Rotation origin: %f, %f\n", x, y);
	}

	void TextureRotatable::setRotationOrigin(FVector rotationOrigin) {
		setRotationOrigin(rotationOrigin.x, rotationOrigin.y);
	}

	void TextureRotatable::setRotationOrigin(RectAnchor rotationAnchor) {
		setRotationOrigin(computeAnchorOffset(getWidth(), getHeight(), rotationAnchor));
	}

	float TextureRotatable::getRotationOriginX() const {
		return rotationOrigin.x;
	}

	float TextureRotatable::getRotationOriginY() const {
		return rotationOrigin.y;
	}

	FVector TextureRotatable::getRotationOrigin() const {
		return rotationOrigin;
	}

	SDL_FPoint TextureRotatable::getRotationOriginSDL() const {
		return SDL_FPoint(rotationOrigin.x, rotationOrigin.y);
	}

	void TextureRotatable::setVerticalFlip() {
		flipMode = SDL_FlipMode::SDL_FLIP_VERTICAL;
	}

	void TextureRotatable::setHorizontalFlip() {
		flipMode = SDL_FlipMode::SDL_FLIP_HORIZONTAL;
	}

	void TextureRotatable::disableFlip() {
		flipMode = SDL_FlipMode::SDL_FLIP_NONE;
	}

	void TextureRotatable::setFlipMode(const SDL_FlipMode& mode) {
		flipMode = mode;
	}

	SDL_FlipMode TextureRotatable::getFlipMode() const {
		return flipMode;
	}

	const SDL_FlipMode& TextureRotatable::getFlipModeRef() const {
		return flipMode;
	}
}