#pragma once
#ifndef RENDERABLE_H
#define RENDERABLE_H

//Using SDL
#include <SDL3/SDL.h>
#include <print>

namespace CE {
	class Renderable
	{
	public:
		virtual void render() const = 0;
		virtual void init() = 0;

		float getX() const;
		void setX(float x);

		float getY() const;
		void setY(float y);

		float getWidth() const;

		float getHeight() const;

		double getRotation() const;
		void setRotation(double rotation);

		void enableRotation();
		void disableRotation();
		bool isRotationEnabled() const;

		float getScale() const;
		void setScale(float scale);

		float getOpacity() const;
		void setOpacity(float opacity);

	protected:
		void setWidth(float width);
		void setHeight(float height);

		SDL_FRect getRect() const;
		const SDL_FRect* getRectPtr() const;
		void setRect(const SDL_FRect& rect);	

	private:
		SDL_FRect rect;		// x, y must refer to the top left corner. Careful: SDL_BlitSurface use SDL_Rect, convert to int in working with surfaces
		bool rotationEnabled;	// Set false for an slight gain in performance if rotations are not needed
		double rotation;
		float opacity;			// [0, 1]
		float scale;			// SDL scale origin managed under the hood


	};
}

#endif // !RENDERABLE_H