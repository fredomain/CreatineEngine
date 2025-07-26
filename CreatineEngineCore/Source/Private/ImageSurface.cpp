#include "ImageSurface.h"

namespace CE {
	ImageSurface::ImageSurface(std::string path) : imageSurfaceGenerator{ std::move(path) } {

	}

	void ImageSurface::load() {
		setData(imageSurfaceGenerator.getSurface());
	}
}