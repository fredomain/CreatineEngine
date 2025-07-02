#include "Assets/TextAssetGPU.h"

namespace CE {
	TextAssetGPU::TextAssetGPU(SDL_Renderer* renderer, std::string text, std::string fontPath, int textSize, SDL_Color textColor)
		: TextureAsset(renderer, std::move(fontPath)), text(text) , textSize(textSize), textWidth(0), textHeight(0), textColor(textColor)
	{
		textFont = TTF_OpenFont(getPath().c_str(), textSize);
	}

	bool TextAssetGPU::load()
	{
		bool success = true;

		textFont = TTF_OpenFont(getPath().c_str(), textSize); //Reload the font in case we change the size

		if (textFont == nullptr)
		{
			printf("Error loading the font: %s\n", SDL_GetError());
			success = false;
		}

		//Remove previous texture to avoid memory leaks
		SDL_DestroyTexture(texture.get());

		//We create a surface from the text string, the font and color. The length value 0 means we compute the length by reading all characters until we reach a NULL characted (let's say automatic length detection)
		SDL_Surface* textSurface = TTF_RenderText_Solid(textFont, text.c_str(), 0, textColor);

		//If error, we print the error message
		if (textSurface == nullptr)
		{
			printf("Error creating a surface from the given text: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Convert surface into texture and check for errors
			texture.reset(SDL_CreateTextureFromSurface(getRenderer(), textSurface));
			if (texture == nullptr)
			{
				printf("Error converting text surface into texture: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Update the text texture dimensions
				textWidth = textSurface->w;
				textHeight = textSurface->h;
			}
			//Surface is no longer needed
			SDL_DestroySurface(textSurface);
			textSurface = nullptr;
		}

		return success;
	}
}
