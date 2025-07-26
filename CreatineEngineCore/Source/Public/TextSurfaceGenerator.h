#pragma once
#ifndef TEXTSURFACEGENERATOR_H
#define TEXTSURFACEGENERATOR_H

#include "SurfaceGenerator.h"

namespace CE {

	class TextSurfaceGenerator : public SurfaceGenerator
	{
	public:
		TextSurfaceGenerator(
			std::string text,
			TTF_Font* font,
			size_t textSize,
			SDL_Color textColor
		);

		SDL_Surface* getSurface() const override;

		std::string getText() const;
		void setText(std::string text);

		TTF_Font* getFont() const;
		void setFont(TTF_Font* font);

		size_t getTextSize() const;
		void setTextSize(size_t textSize);

		SDL_Color getTextColor() const;
		void setTextColor(SDL_Color textColor);

	private:
		std::string text;
		TTF_Font* font;
		size_t textSize;
		SDL_Color textColor;
	};

}

#endif

