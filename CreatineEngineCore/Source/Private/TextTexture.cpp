#include "TextTexture.h"

namespace CE {
	
	/**
	 * @brief Constructs a Texture object from a text string using the specified font, size, and color.
	 * @param renderer Pointer to the SDL_Renderer used for rendering the texture.
	 * @param text The text string to render as a texture.
	 * @param font Pointer to the TTF_Font used to render the text.
	 * @param textSize The size of the text to render.
	 * @param textColor The color to use when rendering the text.
	 */
	TextTexture::TextTexture(
		SDL_Renderer* renderer,
		std::string text,
		TTF_Font* font,
		size_t textSize,
		SDL_Color textColor
	) :
		textSurfaceGenerator{ std::move(text), font, textSize, textColor }
	{
		setRenderer(renderer);
	}

	void TextTexture::load() {
		SDL_Surface* surface = textSurfaceGenerator.getSurface();
		createFromSDL_Surface(surface);
		SDL_DestroySurface(surface);
	}

}