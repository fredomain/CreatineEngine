#pragma once
#ifndef RENDERABLE_H
#define RENDERABLE_H

//Using SDL
#include <SDL3/SDL.h>
#include "FVector.h"
#include "RectAnchor.h"
#include <SDL_ttf.h>
#include <print>

namespace CE {
	class Renderable
	{
	public:
		// Virtual pure functions
		virtual void render() const = 0;		
		virtual void init() = 0;
		virtual void createFromString(std::string text, TTF_Font* font, size_t textSize, SDL_Color textColor) = 0;

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
			RectAnchor posAnchor = RectAnchor::TOP_LEFT,
			FVector posAnchorOffset = FVector(0.0f, 0.0f),
			FVector scale = FVector(1.0f, 1.0f),
			float opacity = 1.0
			);

		// Use these functions to set the source width and height
		void setSourceWidth(float width);
		void setSourceHeight(float height);
		
		SDL_FRect getSourceRect() const;
		const SDL_FRect* getSourceRectPtr() const;
		void setSourceRect(const SDL_FRect& rect);

		SDL_FRect getDestinationRect() const;
		const SDL_FRect* getDestinationRectPtr() const;

		FVector computeAnchorOffset(float w, float h, RectAnchor anchor) const;
		void updateAnchorOffset();

	private:
		SDL_FRect sourceRect;			// Must be setted in derived classes. x, y refer to the top left corner. Careful: SDL_BlitSurface use SDL_Rect, convert to int in working with surfaces
		SDL_FRect destinationRect;		// Used to render, x, y, scale, rotation (and its local rotation axis position), flip operations applies to this destination rect

		FVector position;				// User selected coordinates (x, y). Destination rendering.
		RectAnchor posAnchor;			// Destination rect anchor. Used to select redering coordinates anchor (it is also the scalation origin)
		FVector posAnchorOffset;		// Destination rect anchor offset. Relative vector between SDL position origin (top left corner) - anchor selected position

		FVector scale;					// Scale origin is the same than the coordinates anchor

		float opacity;					// Range [0, 255]

	};
}

#endif // !RENDERABLE_H