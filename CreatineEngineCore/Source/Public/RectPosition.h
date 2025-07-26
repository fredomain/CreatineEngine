#pragma once
#ifndef RECTPOSITION_H
#define RECTPOSITION_H

#include "RectAnchor.h"
#include <SDL3/SDL.h>

namespace CE {

	class RectPosition
	{
		SDL_FRect rect;
		RectAnchor anchor;
	};

}

#endif

