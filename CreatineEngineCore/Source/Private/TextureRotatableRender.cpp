#include "TextureRotatableRender.h"
#include "MathConstants.h"

namespace CE {

	TextureRotatableRender::TextureRotatableRender(
		SDL_Renderer* renderer,
		SDL_Texture* texture,
		double rotation,
		FVector rotationOrigin,
		SDL_FlipMode flipMode
	) :
		TextureRender(renderer, texture),
		rotation(rotation),
		rotationOrigin(rotationOrigin),
		flipMode(flipMode) {

	}

	TextureRotatableRender::TextureRotatableRender(
		SDL_Renderer* renderer,
		SDL_Surface* surface,
		double rotation,
		FVector rotationOrigin,
		SDL_FlipMode flipMode
	) :
		TextureRender(renderer, surface),
		rotation(rotation),
		rotationOrigin(rotationOrigin),
		flipMode(flipMode) {

	}

	TextureRotatableRender::TextureRotatableRender(
		SDL_Renderer* renderer,
		ImageLoader& imageLoader,
		double rotation,
		FVector rotationOrigin,
		SDL_FlipMode flipMode
	) :

		TextureRender(renderer, imageLoader),
		rotation(rotation),
		rotationOrigin(rotationOrigin),
		flipMode(flipMode) {

	}

	TextureRotatableRender::TextureRotatableRender(
		SDL_Renderer* renderer,
		std::string text,
		TTF_Font* font,
		size_t textSize,
		SDL_Color textColor,
		double rotation,
		FVector rotationOrigin,
		SDL_FlipMode flipMode
	) :
		TextureRender(renderer, text, font, textSize, textColor),
		rotation(rotation),
		rotationOrigin(rotationOrigin),
		flipMode(flipMode) {

	}

	void TextureRotatableRender::render() const {

		if (std::abs(getRotation()) > CE::NEAR_ZERO_THRESHOLD) {		// render with rotation
			SDL_FPoint rotationOriginSDL(getRotationOriginSDL());
			SDL_RenderTextureRotated(renderer, data, getSourceRectPtr(), getDestinationRectPtr(), getRotation(), &rotationOriginSDL, getFlipMode());
			//SDL_Log("renderRotated");
		}
		else {
			TextureRender::render();
		}
	}

	void TextureRotatableRender::init() {
		TextureRender::init();

		// Initialize parameters
		rotation = 0.0;
		setRotationOrigin(RectAnchor::CENTER);
	}

	double TextureRotatableRender::getRotation() const {
		return rotation;
	}

	void TextureRotatableRender::setRotation(double rotation) {
		this->rotation = rotation;
	}

	void TextureRotatableRender::setRotationOrigin(float x, float y) {
		rotationOrigin.x = x;
		rotationOrigin.y = y;
		//printf("Rotation origin: %f, %f\n", x, y);
	}

	void TextureRotatableRender::setRotationOrigin(FVector rotationOrigin) {
		setRotationOrigin(rotationOrigin.x, rotationOrigin.y);
	}

	void TextureRotatableRender::setRotationOrigin(RectAnchor rotationAnchor) {
		setRotationOrigin(computeAnchorOffset(getWidth(), getHeight(), rotationAnchor));
	}

	float TextureRotatableRender::getRotationOriginX() const {
		return rotationOrigin.x;
	}

	float TextureRotatableRender::getRotationOriginY() const {
		return rotationOrigin.y;
	}

	FVector TextureRotatableRender::getRotationOrigin() const {
		return rotationOrigin;
	}

	SDL_FPoint TextureRotatableRender::getRotationOriginSDL() const {
		return SDL_FPoint(rotationOrigin.x, rotationOrigin.y);
	}

	void TextureRotatableRender::setVerticalFlip() {
		flipMode = SDL_FlipMode::SDL_FLIP_VERTICAL;
	}

	void TextureRotatableRender::setHorizontalFlip() {
		flipMode = SDL_FlipMode::SDL_FLIP_HORIZONTAL;
	}

	void TextureRotatableRender::disableFlip() {
		flipMode = SDL_FlipMode::SDL_FLIP_NONE;
	}

	void TextureRotatableRender::setFlipMode(const SDL_FlipMode& mode) {
		flipMode = mode;
	}

	SDL_FlipMode TextureRotatableRender::getFlipMode() const {
		return flipMode;
	}

	const SDL_FlipMode& TextureRotatableRender::getFlipModeRef() const {
		return flipMode;
	}
}