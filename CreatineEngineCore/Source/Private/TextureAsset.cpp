#include "TextureAsset.h"
#include <SDL_image.h>

namespace CE {

    TextureAsset::TextureAsset(SDL_Renderer* renderer, std::string path)
        : Asset(std::move(path)), renderer(renderer), texture(nullptr) {
    }

    void TextureAsset::setRenderer(SDL_Renderer* renderer) {
        this->renderer = renderer;
    }

    SDL_Renderer* TextureAsset::getRenderer() const {
        return renderer;
    }

    const Texture& TextureAsset::getTexture() const {
        return texture;
    }

	bool TextureAsset::load() {
		SDL_Surface* surface_temporal = IMG_Load(getPath().c_str());
		if (surface_temporal == NULL) {
			SDL_Log("Unable to load image %s! SDL Error: %s\n", getPath().c_str(), SDL_GetError());
			return false;
		}
		else {
			// Create texture from surface pixels
			texture.setData(SDL_CreateTextureFromSurface(getRenderer(), surface_temporal));
			if (texture.isValid()) {
				SDL_Log("Unable to create texture from %s! SDL Error: %s\n", getPath().c_str(), SDL_GetError());
				return false;
			}

			SDL_DestroySurface(surface_temporal);	// Get rid of old loaded surface

			return true;
		}
	}

}
