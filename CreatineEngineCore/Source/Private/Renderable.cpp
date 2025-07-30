#include "Renderable.h"
#include "Logger.h"

namespace CE {

	void Renderable::enableRender() {
		executeRender = true;
	}

	void Renderable::disableRender() {
		executeRender = false;
	}

	void Renderable::setRenderOrder(uint8_t renderOrder) {
		this->renderOrder = renderOrder;
	}

	uint8_t Renderable::getRenderOrder() const {
		return renderOrder;
	}

	void Renderable::setSourceWidth(float width) {
		if (width > 0) {
			sourceRect.w = width;
		}
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
			rect.setWidth(sourceRect.w * this->scale.x);
		}
	}

	void Renderable::setScaleY(float scale) {
		if (scale >= 0) {
			this->scale.y = scale;
			rect.setHeight(sourceRect.h * this->scale.y);
		}
	}

	void Renderable::setScale(float scaleX, float scaleY) {
		if (scaleX >= 0 && scaleY >= 0) {
			scale.x = scaleX;
			scale.y = scaleY;
			updateRenderRectSize();
		}
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

	void Renderable::updateRenderRectSize() {
		rect.setSize(sourceRect.w * this->scale.x, sourceRect.h * this->scale.y);
		//Logger::log(LogFileType::Engine, std::format("New renderRectSize: {}, {}", rect.getX(), rect.getY()), LogLevel::Debug);
	}

}