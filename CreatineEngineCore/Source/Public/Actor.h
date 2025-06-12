//ifndef to avoid errors on multiple declarations of this header
#ifndef ACTOR_H
#define ACTOR_H

//Using SDL
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
//#include <SDL_mixer.h>

#include <print>

namespace CE {
	class Actor
	{
	public:
		void Render();

	private:
		float x, y, w, h;		// x, y must refer to the top left corner. Careful: SDL_BlitSurface use SDL_Rect, convert to int in working with surfaces
		float rotation;
		float opacity;			// [0, 1]
		float scale;			// SDL scale origin managed under the hood


	};
}

#endif // !ACTOR_H