#include "Texture.h"
#include "MathConstants.h"

namespace CE {

	Texture::Texture(
		SDL_Renderer* renderer,
		SDL_Texture* texture,
		float rotationEnabled = false,
		double rotation = 0.0,
		FVector rotationOrigin = FVector(0.0f, 0.0f),
		SDL_FlipMode flipMode = SDL_FlipMode::SDL_FLIP_NONE
	) :
		renderer(renderer),
		data(texture),
		rotationEnabled(rotationEnabled),
		rotation(rotation),
		rotationOrigin(rotationOrigin),
		flipMode(flipMode) {

	}

	Texture::Texture(
		SDL_Renderer* renderer,
		SDL_Surface* surface,
		float rotationEnabled = false,
		double rotation = 0.0,
		FVector rotationOrigin = FVector(0.0f, 0.0f),
		SDL_FlipMode flipMode = SDL_FlipMode::SDL_FLIP_NONE
	) :
		renderer(renderer),
		rotationEnabled(rotationEnabled),
		rotation(rotation),
		rotationOrigin(rotationOrigin),
		flipMode(flipMode) {

		createFromSDL_Surface(surface);
	}

	Texture::Texture(
		SDL_Renderer* renderer,
		ImageLoader* imageLoader,
		float rotationEnabled = false,
		double rotation = 0.0,
		FVector rotationOrigin = FVector(0.0f, 0.0f),
		SDL_FlipMode flipMode = SDL_FlipMode::SDL_FLIP_NONE
	) :
		renderer(renderer),
		rotationEnabled(rotationEnabled),
		rotation(rotation),
		rotationOrigin(rotationOrigin),
		flipMode(flipMode) {

	}

	Texture::~Texture() {
		if (data) SDL_DestroyTexture(data);
	}

	Texture::Texture(Texture&& other) noexcept : data(other.data) {
		other.data = nullptr;
	}

	Texture& Texture::operator=(Texture&& other) noexcept {
		if (this != &other) {
			if (data) SDL_DestroyTexture(data);
			data = other.data;
			other.data = nullptr;
		}
		return *this;
	}

	void Texture::render() const {
		if (isRotationEnabled()) {
			if (std::abs(getRotation()) > CE::NEAR_ZERO_THRESHOLD) {		// render with rotation
				renderRotated();
			}
			else {
				renderSimple();
			}
		}
		else {	// no rotation
			renderSimple();
		}
	}

	/**
	 * @brief Create a texture and fills data with it. It do not destroy the SDL_Surface
	 * @param surface The Texture data will be created from this
	 */
	void Texture::createFromSDL_Surface(SDL_Surface* surface) {
		// Create texture from surface pixels
		data = SDL_CreateTextureFromSurface(getRenderer(), surface);
		if (data == nullptr) {
			SDL_Log("Unable to create texture from SDL_Surface! SDL Error: %s\n", SDL_GetError());
			//return false;
		}
		else {
			setSourceWidth(data->w);
			setSourceHeight(data->h);
		}
	}

	void Texture::createFromString(std::string string) {
		// TODO
	}

	void Texture::init() {
		// First, set the source rect size
		//setSourceWidth(static_cast<float>(TextureRenderAsset.getTexture()->w));
		//setSourceHeight(static_cast<float>(TextureRenderAsset.getTexture()->h));
		// Then, destination rect must be set regarding the scale
		setScale(1.0f);
		// Anchor offset can also be set
		setPositionAnchor(getPositionAnchor());
		setPosition(0.0f, 0.0f);

		// Initialize parameters
		setRotationOrigin(RectAnchor::CENTER);
	}

	void Texture::renderSimple() const {
		SDL_RenderTexture(renderer, data, getSourceRectPtr(), getDestinationRectPtr());
		//SDL_Log("renderSimple");
	}
	void Texture::renderRotated() const {
		SDL_FPoint rotationOriginSDL(getRotationOriginSDL());
		SDL_RenderTextureRotated(renderer, data, getSourceRectPtr(), getDestinationRectPtr(), getRotation(), &rotationOriginSDL, getFlipMode());
		//SDL_Log("renderRotated");
	}

	int Texture::getSDL_TextureWidth() const {
		/*int w = 0;
		SDL_QueryTexture(data, nullptr, nullptr, &w, nullptr);
		return w;*/
		return data ? data->w : 0;
	}

	int Texture::getSDL_TextureHeight() const {
		/*int h = 0;
		SDL_QueryTexture(data, nullptr, nullptr, nullptr, &h);
		return h;*/
		return data ? data->h : 0;
	}

	SDL_Texture* Texture::getData() const {
		return data;
	}

	void Texture::setData(SDL_Texture* texture) {
		data = texture;
	}

	bool Texture::isValid() {
		return data ? true : false;
	}

	double Texture::getRotation() const {
		return rotation;
	}

	void Texture::setRotation(double rotation) {
		this->rotation = rotation;
	}

	void Texture::setRotationOrigin(float x, float y) {
		rotationOrigin.x = x;
		rotationOrigin.y = y;
		printf("Rotation origin: %f, %f\n", x, y);
	}

	void Texture::setRotationOrigin(FVector rotationOrigin) {
		setRotationOrigin(rotationOrigin.x, rotationOrigin.y);
	}

	void Texture::setRotationOrigin(RectAnchor rotationAnchor) {
		setRotationOrigin(computeAnchorOffset(getWidth(), getHeight(), rotationAnchor));
	}

	float Texture::getRotationOriginX() const {
		return rotationOrigin.x;
	}

	float Texture::getRotationOriginY() const {
		return rotationOrigin.y;
	}

	FVector Texture::getRotationOrigin() const {
		return rotationOrigin;
	}

	SDL_FPoint Texture::getRotationOriginSDL() const {
		return SDL_FPoint(rotationOrigin.x, rotationOrigin.y);
	}

	void Texture::enableRotation() {
		rotationEnabled = true;
	}

	void Texture::disableRotation() {
		rotationEnabled = false;
	}

	bool Texture::isRotationEnabled() const {
		return rotationEnabled;
	}

	void Texture::setVerticalFlip() {
		flipMode = SDL_FlipMode::SDL_FLIP_VERTICAL;
	}

	void Texture::setHorizontalFlip() {
		flipMode = SDL_FlipMode::SDL_FLIP_HORIZONTAL;
	}

	void Texture::disableFlip() {
		flipMode = SDL_FlipMode::SDL_FLIP_NONE;
	}

	void Texture::setFlipMode(const SDL_FlipMode& mode) {
		flipMode = mode;
	}

	SDL_FlipMode Texture::getFlipMode() const {
		return flipMode;
	}

	const SDL_FlipMode& Texture::getFlipModeRef() const {
		return flipMode;
	}
}
