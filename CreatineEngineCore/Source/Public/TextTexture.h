#pragma once
#ifndef TEXTTEXTURE_H
#define TEXTTEXTURE_H

#include "Texture.h"
#include "TextSurfaceGenerator.h"

namespace CE {

	class TextTexture : public Texture
	{
	public:
		TextTexture() = delete;
		TextTexture(
			SDL_Renderer* renderer,
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

