#pragma once
#ifndef ANCHOREDFRECT_H
#define ANCHOREDFRECT_H

#include "RectAnchor.h"
#include <SDL3/SDL.h>

namespace CE {

	class AnchoredFRect
	{
	public:
		// User position operations
		float getX() const;
		void setX(float x);

		float getY() const;
		void setY(float y);

		/**
		 * @brief Set screen coordinates
		 * @param x x-axis position
		 * @param y y-axis position
		 */
		void setPosition(float x, float y);
		void setPosition(const FVector& position);
		FVector getPosition() const;
		
		void setAnchor(RectAnchor anchor);
		RectAnchor getAnchor() const;
		FVector getAnchorOffset() const;

		// Internal rect position (top left corner frame)
		FVector getRectPosition() const;
		const SDL_FRect* getRect() const;

		// Size operations
		float getWidth() const;
		float getHeight() const;
		void setWidth(float w);
		void setHeight(float h);
		void setSize(float w, float h);

	protected:
		//void updateAnchorOffset(FVector position);		// Give it the current user position

	private:
		SDL_FRect rect{0.0f, 0.0f, 0.0f, 0.0f};			// Real rect position (top left corner) and size
		FVector anchorOffset = FVector(0.0f, 0.0f);		// Relative vector between the real rect position origin (top left corner) and the anchor selected position
		RectAnchor anchor = RectAnchor::TOP_LEFT;		// Rect anchor

	};

}

#endif

