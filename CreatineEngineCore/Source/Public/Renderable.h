//ifndef to avoid errors on multiple declarations of this header
#ifndef RENDERABLE_H
#define RENDERABLE_H

//Using SDL
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
//#include <SDL_mixer.h>

#include <print>

namespace CE {
	class Renderable
	{
	public:
		virtual void render() const = 0;

		float getX() const;
		void setX(float x);

		float getY() const;
		void setY(float y);

		float getWidth() const;
		void setWidth(float width);

		float getHeight() const;
		void setHeight(float height);

		float getRotation() const;
		void setRotation(float rotation);

		float getOpacity() const;
		void setOpacity(float opacity);

		float getScale() const;
		void setScale(float scale);



	private:
		SDL_FRect rect;		// x, y must refer to the top left corner. Careful: SDL_BlitSurface use SDL_Rect, convert to int in working with surfaces
		float rotation;
		float opacity;			// [0, 1]
		float scale;			// SDL scale origin managed under the hood


	};
}

#endif // !RENDERABLE_H