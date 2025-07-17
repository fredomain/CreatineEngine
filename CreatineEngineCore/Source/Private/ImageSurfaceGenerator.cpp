#include "ImageSurfaceGenerator.h"
#include <SDL_image.h>
#include <stdexcept>

namespace CE {

	ImageSurfaceGenerator::ImageSurfaceGenerator(std::string path) : path(std::move(path)) {

	}

	SDL_Surface* ImageSurfaceGenerator::getSurface() const {
		SDL_Surface* surface = IMG_Load(path.c_str());
		if (!surface) {
			throw std::runtime_error(SDL_GetError());
		}

		return surface;
	}

	std::string ImageSurfaceGenerator::getPath() const {
		return path;
	}

	void ImageSurfaceGenerator::setPath(std::string newPath) {
		path = std::move(newPath);
	}

}