#include "Assets/ImageAssetGPU.h"
#include <SDL_image.h>

namespace CE {

	ImageAssetGPU::ImageAssetGPU(SDL_Renderer* renderer, std::string path)
		: TextureAsset(renderer, std::move(path)) {
	}

	bool ImageAssetGPU::load(){
		SDL_Surface* surface_temporal = IMG_Load(getPath().c_str());
		if (surface_temporal == NULL) {
			SDL_Log("Unable to load image %s! SDL Error: %s\n", getPath().c_str(), SDL_GetError());
			return false;
		}else {
			//Create texture from surface pixels
			texture = std::unique_ptr<SDL_Texture, SDL_TextureDestroyer>(SDL_CreateTextureFromSurface(getRenderer(), surface_temporal));
			if (texture == NULL) {
				SDL_Log("Unable to create texture from %s! SDL Error: %s\n", getPath().c_str(), SDL_GetError());
				return false;
			}
			
			SDL_DestroySurface(surface_temporal);	// Get rid of old loaded surface

			return true;
		}
	}
}