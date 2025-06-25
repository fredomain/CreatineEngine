#include "Image.h"
#include "MathConstants.h"

namespace CE {

	Image::Image(SDL_Renderer* renderer, std::string path, bool rotation_enabled)
		: imageAsset(renderer, std::move(path)) {
		rotation_enabled ? enableRotation() : disableRotation();
		
	}

	void Image::render() const {
		if (isRotationEnabled()) {	
			if (std::abs(getRotation()) > CE::NEAR_ZERO_THRESHOLD) {		// render with rotation
				renderRotated();
			}else {
				renderSimple();
			}
		}
		else {	// no rotation
			renderSimple();
		}		
	}

	void Image::init() {
		setWidth(imageAsset.getTexture()->w);
		setHeight(imageAsset.getTexture()->h);
	}

	void Image::renderSimple() const{
		SDL_RenderTexture(imageAsset.getRenderer(), imageAsset.getTexture(), NULL, getRectPtr());
		//SDL_Log("renderSimple");
	}
	void Image::renderRotated() const{
		SDL_RenderTextureRotated(imageAsset.getRenderer(), imageAsset.getTexture(), NULL, getRectPtr(), getRotation(), NULL, SDL_FlipMode::SDL_FLIP_NONE);
		//SDL_Log("renderRotated");
	}
}
