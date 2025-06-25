#include "ImageAssetGPU.h"
#include <SDL_image.h>

namespace CE {

	ImageAssetGPU::ImageAssetGPU(SDL_Renderer* renderer, std::string path)
		: TextureAsset(renderer, path) {
	}

	bool ImageAssetGPU::load(){
		SDL_Surface* surface_temporal = IMG_Load(getPath().c_str());
		if (surface_temporal == NULL) {
			SDL_Log("Unable to load image %s! SDL Error: %s\n", "character.png", SDL_GetError());
			return false;
		}else {
			//Create texture from surface pixels
			texture = SDL_CreateTextureFromSurface(renderer, surface_temporal);
			if (texture == NULL) {
				printf("Unable to create texture from %s! SDL Error: %s\n", "character.png", SDL_GetError());
				return false;
			}
			
			SDL_DestroySurface(surface_temporal);	// Get rid of old loaded surface

			return true;
		}
	}
}