#pragma once
#ifndef RENDERABLE_H
#define RENDERABLE_H

//Using SDL
#include <SDL3/SDL.h>
#include "FVector.h"
#include "AnchoredFRect.h"

#include <print>

namespace CE {
	
	/**
	 * @brief Renderable is an abstract base class representing objects that can be rendered.
	 */
	class Renderable
	{
	public:
		AnchoredFRect rect;		// Render destination rect

		void enableRender();
		void disableRender();
		virtual void render() const = 0;

		// Render priority
		void setRenderOrder(uint8_t renderOrder);
		uint8_t getRenderOrder() const;

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

		// Use these functions to set the source width and height
		void setSourceWidth(float width);
		void setSourceHeight(float height);
		
		SDL_FRect getSourceRect() const;
		const SDL_FRect* getSourceRectPtr() const;
		void setSourceRect(const SDL_FRect& rect);
		void updateRenderRectSize();

	private:
		bool executeRender = true;							// Enable or disable rendering
		uint8_t renderOrder = 0;							// Render priority [0,255] (0 -> render in the background)

		SDL_FRect sourceRect{ 0.0f, 0.0f, 0.0f, 0.0f };		// Must be setted in derived classes. x, y refer to the top left corner. Careful: SDL_BlitSurface use SDL_Rect, convert to int in working with surfaces
		FVector scale = FVector(1.0f, 1.0f);				// Scale origin is the same than the coordinates anchor
		float opacity = 1.0f;								// Range [0, 255]

	};
}

#endif // !RENDERABLE_H