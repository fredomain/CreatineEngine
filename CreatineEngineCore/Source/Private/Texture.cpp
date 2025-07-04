#include "Texture.h"

namespace CE {

	Texture::Texture(
		SDL_Renderer* renderer,
		SDL_Texture* texture
	) :
		renderer(renderer),
		data(texture){
	}

	Texture::Texture(
		SDL_Renderer* renderer,
		SDL_Surface* surface
	) :
		renderer(renderer){

		createFromSDL_Surface(surface);
	}

	Texture::Texture(
		SDL_Renderer* renderer,
		ImageLoader& imageLoader
	) :
		renderer(renderer) {

		imageLoader.setLoadCallback(&Texture::onSurfaceLoaded, this);
	}

	Texture::Texture(
		SDL_Renderer* renderer,
		std::string text,
		TTF_Font* font,
		size_t textSize,
		SDL_Color textColor
	) :
		renderer(renderer) {

		createFromString(text, font, textSize, textColor);
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

	void Texture::createFromString(std::string text, TTF_Font* font, size_t textSize, SDL_Color textColor) {
		SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), textSize, textColor);	// Create a temporal surface (it will be converted to SDL_Texture)
		if (surface == NULL)
		{
			printf("Unable to render text surface! SDL_ttf Error: %s\n", SDL_GetError());
		}
		else {
			createFromSDL_Surface(surface);
			SDL_DestroySurface(surface);	// Destroy the temporal surface
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
	}

	void Texture::addUpdateCallback(UpdateCallback cb, void* callbackObject){
		observerMap[callbackObject] = cb;
	}

	void Texture::removeUpdateCallback(void* callbackObject){
		if (callbackObject) {
			observerMap.erase(callbackObject);
		}		
	}

	void Texture::setRenderer(SDL_Renderer* renderer) {
		this->renderer = renderer;
	}

	SDL_Renderer* Texture::getRenderer() const {
		return renderer;
	}

	int Texture::getWidth() const {
		/*int w = 0;
		SDL_QueryTexture(data, nullptr, nullptr, &w, nullptr);
		return w;*/
		return data ? data->w : 0;
	}

	int Texture::getHeight() const {
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

	void Texture::onSurfaceLoaded(SDL_Surface* surface, void* callbackObject) {
		Texture* self = static_cast<Texture*>(callbackObject);
		self->createFromSDL_Surface(surface);

		// Notify observers
		for (const auto& [obj, cb] : self->observerMap) {
			cb(obj);
		}

	}
}
