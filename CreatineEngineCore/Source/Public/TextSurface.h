#pragma once
#ifndef TEXTSURFACE_H
#define TEXTSURFACE_H

#include "Surface.h"
#include "TextSurfaceGenerator.h"

namespace CE {

	class TextSurface : public Surface
	{
	public:
		TextSurface() = delete;
		TextSurface(
			std::string text,
			TTF_Font* font,
			size_t textSize,
			SDL_Color textColor
		);

		void load() override;

		TextSurfaceGenerator textSurfaceGenerator;
	};

}

#endif

