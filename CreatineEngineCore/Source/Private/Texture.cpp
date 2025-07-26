#include "Texture.h"
#include <memory>
#include <string>
#include "Logger.h"

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

	Texture::~Texture() {
		if (data) SDL_DestroyTexture(data);
	}

	void Texture::load() {

	}

	bool Texture::isLoaded() const {
		return isValid();
	}

	/**
	 * @brief Create a texture and fills data with it. It do not destroy the SDL_Surface
	 * @param surface The Texture data will be created from this
	 */
	void Texture::createFromSDL_Surface(SDL_Surface* surface) {
		// Create texture from surface pixels
		setData(SDL_CreateTextureFromSurface(getRenderer(), surface));
		if (data == nullptr) {
			SDL_Log("Unable to create texture from SDL_Surface! SDL Error: %s\n", SDL_GetError());
			//return false;
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
		if (texture) {
			data = texture;
			observerBroadcast.notifyObservers();	// If data is set, notify observers
		}		
	}

	bool Texture::isValid() const {
		return data ? true : false;
	}

}
