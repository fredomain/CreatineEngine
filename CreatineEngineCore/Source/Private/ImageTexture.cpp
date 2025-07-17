#include "ImageTexture.h"

namespace CE {

	ImageTexture::ImageTexture(SDL_Renderer* renderer, std::string path) :
		imageSurfaceGenerator{ std::move(path) }
	{
		setRenderer(renderer);
	}

	void ImageTexture::load() {
		SDL_Surface* surface = imageSurfaceGenerator.getSurface();
		createFromSDL_Surface(surface);
		SDL_DestroySurface(surface);
	}

}
