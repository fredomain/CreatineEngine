#pragma once
#ifndef RECT_H
#define RECT_H

#include "RectAnchor.h"
#include <SDL3/SDL.h>

namespace CE {

	class Rect
	{
		SDL_FRect rect;
		RectAnchor anchor;
	};

}

#endif

