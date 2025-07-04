#include "TextureRotatableInstance.h"
#include "MathConstants.h"

namespace CE {

	TextureRotatableInstance::TextureRotatableInstance(Texture& texture) : TextureInstance(texture) {
	}
	TextureRotatableInstance::~TextureRotatableInstance(){
		TextureInstance::~TextureInstance();
	}

	void TextureRotatableInstance::render() const {

		if (std::abs(getRotation()) > CE::NEAR_ZERO_THRESHOLD) {		// render with rotation
			SDL_FPoint rotationOriginSDL(getRotationOriginSDL());
			SDL_RenderTextureRotated(texture->getRenderer(), texture->getData(), getSourceRectPtr(), getDestinationRectPtr(), getRotation(), &rotationOriginSDL, getFlipMode());
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