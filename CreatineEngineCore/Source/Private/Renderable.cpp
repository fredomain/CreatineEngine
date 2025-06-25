#include "Renderable.h"

namespace CE {
	float Renderable::getX() const{
		return rect.x;
	}

	void Renderable::setX(float x){
		rect.x = x;
	}

	float Renderable::getY() const {
		return rect.y;
	}

	void Renderable::setY(float y) {
		rect.y = y;
	}

	float Renderable::getWidth() const {
		return rect.w;
	}

	void Renderable::setWidth(float width) {
		if (width > 0) {
			rect.w = width;
		}		
	}

	float Renderable::getHeight() const {
		return rect.h;
	}

	void Renderable::setHeight(float height) {
		if (height > 0) {
			rect.h = height;
		}
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

	float Renderable::getScale() const {
		return scale;
	}

	void Renderable::setScale(float scale) {
		if (scale >= 0 && scale <= 1) {
			this->scale = scale;
		}
	}

	float Renderable::getOpacity() const {
		return opacity;
	}

	void Renderable::setOpacity(float opacity) {
		if (scale >= 0 && scale <= 255) {
			this->opacity = opacity;
		}
	}	

	SDL_FRect Renderable::getRect() const {
		return rect;
	}
	const SDL_FRect* Renderable::getRectPtr() const {
		return const_cast<const SDL_FRect*>(&rect);
	}
	void Renderable::setRect(const SDL_FRect& rect) {
		this->rect = rect;
	}
}