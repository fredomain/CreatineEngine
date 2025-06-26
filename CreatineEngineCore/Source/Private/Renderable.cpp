#include "Renderable.h"

namespace CE {
	//Renderable::Renderable() : rect

	float Renderable::getX() const{
		return destinationRect.x;
	}

	void Renderable::setX(float x){
		destinationRect.x = x;
	}

	float Renderable::getY() const {
		return destinationRect.y;
	}

	void Renderable::setY(float y) {
		destinationRect.y = y;
	}

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
		destinationAnchor = anchor;
	}

	RectAnchor Renderable::getPositionAnchor() const{

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
		}
	}

	void Renderable::setScaleY(float scale) {
		if (scale >= 0) {
			this->scale.y = scale;
			destinationRect.h = sourceRect.h * this->scale.y;
		}
	}

	void Renderable::setScale(float scale) {
		setScaleX(scale);
		setScaleY(scale);
	}

	void Renderable::setScale(FVector scale) {
		setScaleX(scale.x);
		setScaleY(scale.y);
	}

	float Renderable::getScaleX() const {
		return scale.x;
	}

	float Renderable::getScaleY() const {
		return scale.y;
	}

	double Renderable::getRotation() const {
		return rotation;
	}

	void Renderable::setRotation(double rotation) {
		this->rotation = rotation;
	}

	void Renderable::enableRotation(){
		rotationEnabled = true;
	}

	void Renderable::disableRotation() {
		rotationEnabled = false;
	}

	bool Renderable::isRotationEnabled() const{
		return rotationEnabled;
	}

	void Renderable::setVerticalFlip() {
		flipMode = SDL_FlipMode::SDL_FLIP_VERTICAL;
	}

	void Renderable::setHorizontalFlip() {
		flipMode = SDL_FlipMode::SDL_FLIP_HORIZONTAL;
	}

	void Renderable::disableFlip() {
		flipMode = SDL_FlipMode::SDL_FLIP_NONE;
	}

	void Renderable::setFlipMode(const SDL_FlipMode& mode) {
		flipMode = mode;
	}

	SDL_FlipMode Renderable::getFlipMode() const {
		return flipMode;
	}

	const SDL_FlipMode& Renderable::getFlipModeRef() const {
		return flipMode;
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