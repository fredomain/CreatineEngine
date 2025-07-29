#include "TextureInstanceRotatable.h"
#include "MathConstants.h"
#include "Logger.h"

namespace CE {

	TextureInstanceRotatable::TextureInstanceRotatable(
		std::shared_ptr<Texture> texture,
		double rotation,
		FVector rotationOrigin,
		SDL_FlipMode flipMode
	) : TextureInstance(texture),
		rotation(rotation),
		rotationOrigin(rotationOrigin),
		flipMode(flipMode){
	}

	TextureInstanceRotatable::~TextureInstanceRotatable(){
		TextureInstance::~TextureInstance();
	}

	void TextureInstanceRotatable::render() const {
		//Logger::log(LogFileType::Engine, "Rendering TextureInstanceRotatable", LogLevel::Verbose);
		if (std::abs(getRotation()) > CE::NEAR_ZERO_THRESHOLD) {		// render with rotation
			SDL_FPoint rotationOriginSDL(getRotationOriginSDL());
			SDL_RenderTextureRotated(texture->getRenderer(), texture->getData(), getSourceRectPtr(), rect.getRect(), getRotation(), &rotationOriginSDL, getFlipMode());
			//SDL_Log("renderRotated");
		}
		else {
			TextureInstance::render();
		}
	}

	/*void TextureInstanceRotatable::init() {
		TextureInstance::init();

		// Initialize parameters
		rotation = 0.0;
		setRotationOrigin(RectAnchor::CENTER);
	}*/

	double TextureInstanceRotatable::getRotation() const {
		return rotation;
	}

	void TextureInstanceRotatable::setRotation(double rotation) {
		this->rotation = rotation;
	}

	void TextureInstanceRotatable::setRotationOrigin(float x, float y) {
		rotationOrigin.x = x;
		rotationOrigin.y = y;
		//printf("Rotation origin: %f, %f\n", x, y);
	}

	void TextureInstanceRotatable::setRotationOrigin(FVector rotationOrigin) {
		setRotationOrigin(rotationOrigin.x, rotationOrigin.y);
	}

	void TextureInstanceRotatable::setRotationOrigin(RectAnchor rotationAnchor) {
		setRotationOrigin(computeAnchorOffset(rect.getWidth(), rect.getHeight(), rotationAnchor));
	}

	float TextureInstanceRotatable::getRotationOriginX() const {
		return rotationOrigin.x;
	}

	float TextureInstanceRotatable::getRotationOriginY() const {
		return rotationOrigin.y;
	}

	FVector TextureInstanceRotatable::getRotationOrigin() const {
		return rotationOrigin;
	}

	SDL_FPoint TextureInstanceRotatable::getRotationOriginSDL() const {
		return SDL_FPoint(rotationOrigin.x, rotationOrigin.y);
	}

	void TextureInstanceRotatable::setVerticalFlip() {
		flipMode = SDL_FlipMode::SDL_FLIP_VERTICAL;
	}

	void TextureInstanceRotatable::setHorizontalFlip() {
		flipMode = SDL_FlipMode::SDL_FLIP_HORIZONTAL;
	}

	void TextureInstanceRotatable::disableFlip() {
		flipMode = SDL_FlipMode::SDL_FLIP_NONE;
	}

	void TextureInstanceRotatable::setFlipMode(const SDL_FlipMode& mode) {
		flipMode = mode;
	}

	SDL_FlipMode TextureInstanceRotatable::getFlipMode() const {
		return flipMode;
	}

	const SDL_FlipMode& TextureInstanceRotatable::getFlipModeRef() const {
		return flipMode;
	}
}