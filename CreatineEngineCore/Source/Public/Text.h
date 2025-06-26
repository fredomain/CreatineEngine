#pragma once
#ifndef TEXT_H
#define TEXT_H

#include "TextureAsset.h"
#include <SDL3/SDL.h>
#include<SDL_ttf.h>

namespace CE {
	class Text : public TextureAsset
	{
	public:
		/** CONSTRUCTORS SEGUIR AQUI */
		TextAsset(SDL_Renderer* renderer, std::string& text, std::string& fontPath, SDL_Color textColor = { 0,0,0 }, AssetManager* assetManager = nullptr);
		TextAsset(SDL_Renderer* renderer, std::string&& text, std::string& fontPath, SDL_Color textColor = { 0,0,0 }, AssetManager* assetManager = nullptr);
		TextAsset(SDL_Renderer* renderer, std::string& text, std::string&& fontPath, SDL_Color textColor = { 0,0,0 }, AssetManager* assetManager = nullptr);
		TextAsset(SDL_Renderer* renderer, std::string&& text, std::string&& fontPath, SDL_Color textColor = { 0,0,0 }, AssetManager* assetManager = nullptr);
		~TextAsset();

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

		/*SDL variables */
		SDL_Texture* texture;
		SDL_Renderer* renderer;
	};
}

#endif // !TEXT_H