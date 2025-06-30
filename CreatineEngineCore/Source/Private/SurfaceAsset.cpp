#include "SurfaceAsset.h"
#include <SDL_image.h>

namespace CE {

    SurfaceAsset::SurfaceAsset(std::string path)
        : Asset(std::move(path)), surface(nullptr) {
    }

    const Surface& SurfaceAsset::getSurface() const {
        return surface;
    }

	bool SurfaceAsset::load() {
		surface.setData(IMG_Load(getPath().c_str()));
		if (surface.isValid())
		{
			SDL_Log("Unable to load image %s! SDL Error: %s\n", getPath().c_str(), SDL_GetError());
			return false;
		}

		return true;
	}

}
