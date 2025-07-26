#pragma once
#ifndef SURFACEGENERATOR_H
#define SURFACEGENERATOR_H

#include <SDL3/SDL.h>
#include <SDL_ttf.h>
#include <string>

namespace CE {

	class SurfaceGenerator
	{
	public:
		virtual SDL_Surface* getSurface() const = 0;
	};

}

#endif

