#pragma once
#ifndef RENDERABLE_H
#define RENDERABLE_H

//Using SDL
#include <SDL3/SDL.h>
#include "FVector.h"
#include "RectAnchor.h"
#include <print>

namespace CE {
	class Renderable
	{
	public:
		virtual void render() const = 0;
		virtual void init() = 0;			// After loading assets included in derived classes, if any

		float getX() const;
		void setX(float x);

		float getY() const;
		void setY(float y);

		void setPosition(float x, float y);
		void setPosition(const FVector& position);
		FVector getPosition() const;

		void setPositionAnchor(RectAnchor anchor);
		RectAnchor getPositionAnchor() const;
		
		float getWidth() const;
		float getHeight() const;

		float getSourceWidth() const;
		float getSourceHeight() const;

		void setScaleX(float scaleX);
		void setScaleY(float scaleY);		
		void setScale(float scale);
		void setScale(FVector scale);
		float getScaleX() const;
		float getScaleY() const;

		double getRotation() const;
		void setRotation(double rotation);

		void enableRotation();
		void disableRotation();
		bool isRotationEnabled() const;

		void setVerticalFlip();
		void setHorizontalFlip();
		void disableFlip();
		void setFlipMode(const SDL_FlipMode& mode);
		SDL_FlipMode getFlipMode() const;
		const SDL_FlipMode& getFlipModeRef() const;

		float getOpacity() const;
		void setOpacity(float opacity);

	protected:
		//Renderable();

		// Derived classes must use this to set the source width and height
		void setSourceWidth(float width);
		void setSourceHeight(float height);
		
		SDL_FRect getSourceRect() const;
		const SDL_FRect* getSourceRectPtr() const;
		void setSourceRect(const SDL_FRect& rect);

		SDL_FRect getDestinationRect() const;
		const SDL_FRect* getDestinationRectPtr() const;

	private:
		SDL_FRect sourceRect;					// Must be setted in derived classes. x, y refer to the top left corner. Careful: SDL_BlitSurface use SDL_Rect, convert to int in working with surfaces
		SDL_FRect destinationRect;				// Used to render, x, y, scale, rotation (and its local rotation axis position), flip operations applies to this destination rect

		RectAnchor destinationAnchor;			// Used to select redering coordinates anchor (it is also the scalation origin)
		FVector destinationAnchorOffset;		// Relative vector between 

		FVector scale;						// Scale origin is the same than the coordinates anchor

		bool rotationEnabled;					// Set false for an slight gain in performance if rotations are not needed
		double rotation;						// Unit: degrees
		FVector rotationOrigin;				// Rotation origin
		SDL_FlipMode flipMode;					// Only applies when rotations are enabled

		float opacity;							// Range

	};
}

#endif // !RENDERABLE_H