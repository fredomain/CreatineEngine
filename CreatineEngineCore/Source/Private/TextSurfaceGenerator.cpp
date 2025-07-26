#include "TextSurfaceGenerator.h"

namespace CE {

	/**
	 * @brief Creates an object that allow the construction of a Surface object from a text string using the specified font, size, and color.
	 * @param text The text string to render as a texture.
	 * @param font Pointer to the TTF_Font used to render the text.
	 * @param textSize The size of the text to render.
	 * @param textColor The color to use when rendering the text.
	 */
	TextSurfaceGenerator::TextSurfaceGenerator(
		std::string text,
		TTF_Font* font,
		size_t textSize,
		SDL_Color textColor
	) :
		text(std::move(text)),
		font(font),
		textSize(textSize),
		textColor(textColor){		
	}

	SDL_Surface* TextSurfaceGenerator::getSurface() const{
		SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), textSize, textColor);
		if (surface == NULL)
		{
			//Logger::logMessage()
			printf("Unable to render text surface! SDL_ttf Error: %s\n", SDL_GetError());
		}

		return surface;
	}

	std::string TextSurfaceGenerator::getText() const {
		return text;
	}

	void TextSurfaceGenerator::setText(std::string text) {
		this->text = text;
	}

	TTF_Font* TextSurfaceGenerator::getFont() const {
		return font;
	}

	void TextSurfaceGenerator::setFont(TTF_Font* font) {
		if (font) {
			this->font = font;
		}
	}

	size_t TextSurfaceGenerator::getTextSize() const {
		return textSize;
	}

	void TextSurfaceGenerator::setTextSize(size_t textSize){
		this->textSize = textSize;
	}

	SDL_Color TextSurfaceGenerator::getTextColor() const{
		return textColor;
	}

	void TextSurfaceGenerator::setTextColor(SDL_Color textColor){
		this->textColor = textColor;
	}

}