#include "Image.h"

namespace CE {

	Image::Image(SDL_Renderer* renderer, std::string path)
		: imageAsset(renderer, std::move(path)) {
	}

	void Image::render() const {
		SDL_RenderTexture(imageAsset.getRenderer(), imageAsset.getTexture(), NULL, getRectPtr());
	}

	void Image::init() {
		setWidth(imageAsset.getTexture()->w);
		setHeight(imageAsset.getTexture()->h);
	}
}
