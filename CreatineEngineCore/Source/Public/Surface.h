#pragma once
#ifndef SURFACE_H
#define SURFACE_H

#include <SDL3/SDL.h>

namespace CE {
	class Surface
	{
	public:
		~Surface();

		SDL_Surface data;

	};
}

#endif // !SURFACE_H



