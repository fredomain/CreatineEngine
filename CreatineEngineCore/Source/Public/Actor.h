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
		/* CONSTRUCTORS & DESTRUCTORS */
		Actor();				
		~Actor();				

		/* CLASS SPECIFIC FUNCTIONS */
		void Render();			// Overriden by child classes

		/* SETTERS & GETTERS */
		float x(), y(), w(), h();
		float rotation();
		float opacity();
		float scale();

		void x(float x), y(float y), w(float w), h(float h);
		void rotation(float rotation);
		void opacity(float opacity);
		void scale(float scale);

	private:
		float x_, y_, w_, h_;	// x, y must refer to the top left corner. Careful: SDL_BlitSurface use SDL_Rect, convert to int in working with surfaces
		float rotation_;
		float opacity_;			// [0, 1]
		float scale_;			// SDL scale origin managed under the hood
	};
}

#endif // !ACTOR_H