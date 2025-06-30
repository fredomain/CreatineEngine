#include "TextureRender.h"
#include "MathConstants.h"

namespace CE {

	TextureRender::TextureRender(SDL_Renderer* renderer, std::string path, bool rotation_enabled)
		: TextureAsset(renderer, std::move(path)) {
		rotation_enabled ? enableRotation() : disableRotation();
		
	}

	void TextureRender::render() const {
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

	void TextureRender::init() {
		// First, set the source rect size
		setSourceWidth(static_cast<float>(TextureRenderAsset.getTexture()->w));
		setSourceHeight(static_cast<float>(TextureRenderAsset.getTexture()->h));
		// Then, destination rect must be set regarding the scale
		setScale(1.0f);
		// Anchor offset can also be set
		setPositionAnchor(getPositionAnchor());
		setPosition(0.0f, 0.0f);

		// Initialize parameters
		setRotationOrigin(RectAnchor::CENTER);
	}

	void TextureRender::renderSimple() const{
		SDL_RenderTexture(TextureRenderAsset.getRenderer(), TextureRenderAsset.getTexture(), getSourceRectPtr(), getDestinationRectPtr());
		//SDL_Log("renderSimple");
	}
	void TextureRender::renderRotated() const{
		SDL_FPoint rotationOriginSDL(getRotationOriginSDL());
		SDL_RenderTextureRotated(TextureRenderAsset.getRenderer(), TextureRenderAsset.getTexture(), getSourceRectPtr(), getDestinationRectPtr(), getRotation(), &rotationOriginSDL, getFlipMode());
		//SDL_Log("renderRotated");
	}
}
