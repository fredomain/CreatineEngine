#include "ImageLoader.h"
#include <SDL_image.h>

namespace CE {

    ImageLoader::ImageLoader(std::string path)
        : AssetLoader(std::move(path)) {
    }

	bool ImageLoader::load() {
		/*surface.setData(IMG_Load(getPath().c_str()));
		if (surface.isValid())
		{
			SDL_Log("Unable to load image %s! SDL Error: %s\n", getPath().c_str(), SDL_GetError());
			return false;
		}*/

		return true;
	}

}
