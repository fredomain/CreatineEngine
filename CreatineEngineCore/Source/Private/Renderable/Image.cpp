#include "Renderable/Image.h"
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
		// First, set the source rect size
		setSourceWidth(static_cast<float>(imageAsset.getTexture()->w));
		setSourceHeight(static_cast<float>(imageAsset.getTexture()->h));
		// Then, destination rect must be set regarding the scale
		setUniformScale(1.0f);

		// Initialize parameters
	}

	void Image::renderSimple() const{
		SDL_RenderTexture(imageAsset.getRenderer(), imageAsset.getTexture(), getSourceRectPtr(), getDestinationRectPtr());
		//SDL_Log("renderSimple");
	}
	void Image::renderRotated() const{
		SDL_RenderTextureRotated(imageAsset.getRenderer(), imageAsset.getTexture(), getSourceRectPtr(), getDestinationRectPtr(), getRotation(), NULL, getFlipMode());
		//SDL_Log("renderRotated");
	}
}
