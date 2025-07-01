#include "Assets/ImageAssetCPU.h"
#include <SDL_image.h>

namespace CE {
	ImageAssetCPU::ImageAssetCPU(std::string path)
	: SurfaceAsset(std::move(path)) {
	}

	bool ImageAssetCPU::load() {
		surface = std::unique_ptr<SDL_Surface, SDL_SurfaceDestroyer>(IMG_Load(getPath().c_str()));
		if (surface == NULL)
		{
			SDL_Log("Unable to load image %s! SDL Error: %s\n", getPath().c_str(), SDL_GetError());
			return false;
		}

		return true;
	}
}
