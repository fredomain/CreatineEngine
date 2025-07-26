#include "TextSurface.h"

namespace CE {

	TextSurface::TextSurface(
		std::string text,
		TTF_Font* font,
		size_t textSize,
		SDL_Color textColor
	) : textSurfaceGenerator{text, font, textSize, textColor}
	{

	}

	void TextSurface::load() {
		setData(textSurfaceGenerator.getSurface());
	}

}
