#include "Renderable.h"

namespace CE {
	Renderable::Renderable(
		FVector position,
		RectAnchor posAnchor,
		FVector posAnchorOffset,
		FVector scale,
		float opacity
		) :
		sourceRect(SDL_FRect(0.0f, 0.0f, 0.0f, 0.0f)),
		destinationRect(SDL_FRect(0.0f, 0.0f, 0.0f, 0.0f)),
		position(position),
		posAnchor(posAnchor),
		posAnchorOffset(posAnchorOffset),
		scale(scale),
		opacity(opacity){

	}

	void Renderable::init() {
		// First, set the source rect size
		//setSourceWidth(static_cast<float>(TextureRenderAsset.getTexture()->w));
		//setSourceHeight(static_cast<float>(TextureRenderAsset.getTexture()->h));
		// Then, destination rect must be set regarding the scale
		setScale(1.0f);
		// Anchor offset can also be set
		setPositionAnchor(getPositionAnchor());
		setPosition(0.0f, 0.0f);
	}

	float Renderable::getX() const{
		return position.x;
	}

	void Renderable::setX(float x){
		position.x = x;
		destinationRect.x = x - posAnchorOffset.x;
		//printf("destinationRect.x = %f\n", destinationRect.x);
	}

	float Renderable::getY() const {
		return position.y;
	}

	void Renderable::setY(float y) {
		position.y = y;
		destinationRect.y = y - posAnchorOffset.y;
		//printf("destinationRect.y = %f\n", destinationRect.y);
	}

	/**
	 * @brief Set screen coordinates
	 * @param x x-axis position
	 * @param y y-axis position
	 */
	void Renderable::setPosition(float x, float y) {
		setX(x);
		setY(y);
	}

	void Renderable::setPosition(const FVector& position) {
		setX(position.x);
		setY(position.y);
	}

	FVector Renderable::getPosition() const {
		return FVector{ destinationRect.x, destinationRect.y };
	}

	void Renderable::setPositionAnchor(RectAnchor anchor) {
		posAnchor = anchor;
		// Update the anchor offset
		updateAnchorOffset();
	}

	RectAnchor Renderable::getPositionAnchor() const{
		return posAnchor;
	}

	void Renderable::updateAnchorOffset() {
		posAnchorOffset = computeAnchorOffset(destinationRect.w, destinationRect.h, posAnchor);
		// Update position to reflect the change in the anchor offset (with the current position settings)
		setPosition(getX(), getY());
	}

	FVector Renderable::computeAnchorOffset(float w, float h, RectAnchor anchor) const {
		FVector offset;

		switch (anchor) {
		case RectAnchor::CENTER:
			offset.x = w / 2;
			offset.y = h / 2;
			break;
		case RectAnchor::TOP:
			offset.x = w / 2;
			offset.y = 0;
			break;
		case RectAnchor::BOTTOM:
			offset.x = w / 2;
			offset.y = h;
			break;
		case RectAnchor::LEFT:
			offset.x = 0;
			offset.y = h / 2;
			break;
		case RectAnchor::RIGHT:
			offset.x = w;
			offset.y = h / 2;
			break;
		case RectAnchor::TOP_LEFT:
			offset.x = 0;
			offset.y = 0;
			break;
		case RectAnchor::TOP_RIGHT:
			offset.x = w;
			offset.y = 0;
			break;
		case RectAnchor::BOTTOM_LEFT:
			offset.x = 0;
			offset.y = h;
			break;
		case RectAnchor::BOTTOM_RIGHT:
			offset.x = w;
			offset.y = h;
			break;
		}
		
		return offset;
	}

	float Renderable::getWidth() const {
		return destinationRect.w;
	}

	void Renderable::setSourceWidth(float width) {
		if (width > 0) {
			sourceRect.w = width;
		}		
	}

	float Renderable::getHeight() const {
		return destinationRect.h;
	}

	void Renderable::setSourceHeight(float height) {
		if (height > 0) {
			sourceRect.h = height;
		}
	}

	float Renderable::getSourceWidth() const {
		return sourceRect.w;
	}

	float Renderable::getSourceHeight() const {
		return sourceRect.h;
	}

	void Renderable::setScaleX(float scale) {
		if (scale >= 0) {
			this->scale.x = scale;
			destinationRect.w = sourceRect.w * this->scale.x;
			//printf("destinationRect.w = %f\n", destinationRect.w);
		}
	}

	void Renderable::setScaleY(float scale) {
		if (scale >= 0) {
			this->scale.y = scale;
			destinationRect.h = sourceRect.h * this->scale.y;
			//printf("destinationRect.h = %f\n", destinationRect.h);
		}
	}

	void Renderable::setScale(float scaleX, float scaleY) {
		setScaleX(scaleX);
		setScaleY(scaleY);
		updateAnchorOffset();
	}

	void Renderable::setScale(float scale) {
		setScale(scale, scale);
	}

	void Renderable::setScale(FVector scale) {
		setScale(scale.x, scale.y);
	}

	float Renderable::getScaleX() const {
		return scale.x;
	}

	float Renderable::getScaleY() const {
		return scale.y;
	}

	float Renderable::getOpacity() const {
		return opacity;
	}

	void Renderable::setOpacity(float opacity) {
		if (opacity >= 0 && opacity <= 255) {
			this->opacity = opacity;
		}
	}	

	SDL_FRect Renderable::getSourceRect() const {
		return sourceRect;
	}
	const SDL_FRect* Renderable::getSourceRectPtr() const {
		return const_cast<const SDL_FRect*>(&sourceRect);
	}
	void Renderable::setSourceRect(const SDL_FRect& rect) {
		this->sourceRect = rect;
	}

	SDL_FRect Renderable::getDestinationRect() const {
		return destinationRect;
	}

	const SDL_FRect* Renderable::getDestinationRectPtr() const {
		return const_cast<const SDL_FRect*>(&destinationRect);
	}
}