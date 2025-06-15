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
		rect.w = width;
	}

	float Renderable::getHeight() const {
		return rect.h;
	}

	void Renderable::setHeight(float height) {
		rect.h = height;
	}

	float Renderable::getRotation() const {
		return rotation;
	}

	void Renderable::setRotation(float rotation) {
		this->rotation = rotation;
	}

	float Renderable::getOpacity() const {
		return opacity;
	}

	void Renderable::setOpacity(float opacity) {
		this->opacity = opacity;
	}

	float Renderable::getScale() const {
		return scale;
	}

	void Renderable::setScale(float scale) {
		this->scale = scale;
	}
}