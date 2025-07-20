#pragma once
#ifndef RENDERABLE_H
#define RENDERABLE_H

//Using SDL
#include <SDL3/SDL.h>
#include "FVector.h"
#include "RectAnchor.h"

#include <print>

namespace CE {
	
	/**
	 * @brief Renderable is an abstract base class representing objects that can be rendered.
	 */
	class Renderable
	{
	public:
		void enableRender();
		void disableRender();
		virtual void render() const = 0;

		// Render priority
		void setRenderOrder(uint8_t renderOrder);
		uint8_t getRenderOrder() const;

		// Position operations
		float getX() const;
		void setX(float x);

		float getY() const;
		void setY(float y);

		void setPosition(float x, float y);
		void setPosition(const FVector& position);
		FVector getPosition() const;
		void setPositionAnchor(RectAnchor anchor);
		RectAnchor getPositionAnchor() const;
		FVector getPositionAnchorOffset() const;
		
		// Size operations
		float getWidth() const;
		float getHeight() const;

		float getSourceWidth() const;
		float getSourceHeight() const;

		// Scale operations
		void setScaleX(float scaleX);
		void setScaleY(float scaleY);
		void setScale(float scaleX, float scaleY);
		void setScale(float scale);
		void setScale(FVector scale);
		float getScaleX() const;
		float getScaleY() const;		

		// Opacity operations
		float getOpacity() const;
		void setOpacity(float opacity);

	protected:
		Renderable(
			FVector position = FVector(0.0f, 0.0f),
			RectAnchor positionAnchor = RectAnchor::TOP_LEFT,
			FVector positionAnchorOffset = FVector(0.0f, 0.0f),
			FVector scale = FVector(1.0f, 1.0f),
			float opacity = 1.0
			);

		// Use these functions to set the source width and height
		void setSourceWidth(float width);
		void setSourceHeight(float height);
		
		SDL_FRect getSourceRect() const;
		const SDL_FRect* getSourceRectPtr() const;
		void setSourceRect(const SDL_FRect& rect);
		void updateDestinationRectSize();

		SDL_FRect getDestinationRect() const;
		const SDL_FRect* getDestinationRectPtr() const;

		
		void updateAnchorOffset();

	private:
		bool executeRender = true;				// Enable or disable rendering
		uint8_t renderOrder = 0;			// Render priority [0,255] (0 -> render in the background)

		SDL_FRect sourceRect;			// Must be setted in derived classes. x, y refer to the top left corner. Careful: SDL_BlitSurface use SDL_Rect, convert to int in working with surfaces
		SDL_FRect destinationRect;		// Used to render, x, y, scale, rotation (and its local rotation axis position), flip operations applies to this destination rect

		FVector position;				// User selected coordinates (x, y). Destination rendering.
		RectAnchor positionAnchor;			// Destination rect anchor. Used to select rendering coordinates anchor (it is also the scalation origin)
		FVector positionAnchorOffset;		// Destination rect anchor offset. Relative vector between SDL position origin (top left corner) - anchor selected position

		FVector scale;					// Scale origin is the same than the coordinates anchor

		float opacity;					// Range [0, 255]

	};
}

#endif // !RENDERABLE_H