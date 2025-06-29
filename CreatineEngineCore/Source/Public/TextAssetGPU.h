#pragma once
#ifndef TEXT_H
#define TEXT_H

#include "TextureAsset.h"
#include <SDL3/SDL.h>
#include<SDL_ttf.h>

namespace CE {
	class TextAssetGPU : public TextureAsset
	{
	public:
		/** CONSTRUCTORS SEGUIR AQUI */
		TextAssetGPU(SDL_Renderer* renderer, std::string text, std::string fontPath, int textSize = 10, SDL_Color textColor = { 0,0,0 });
		~TextAssetGPU();

		/** FUNCTIONS */
		bool load() override;


	private:
		/* Text variables */
		std::string text;
		SDL_Color textColor;
		int textSize;
		TTF_Font* textFont;

		/*Intermediate variables */
		int textWidth;
		int textHeight;
	};
}

#endif // !TEXT_H