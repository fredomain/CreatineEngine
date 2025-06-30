#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL3/SDL.h>

namespace CE {
	/**
	 * @brief Wrapper class for SDL_Texture (GPU Image). Contains a pointer to the SDL texture data structure.
	 */
	class Texture {
	public:
		Texture() = default;
		explicit Texture(SDL_Texture* texture);
		~Texture();

		// Delete copy constructor and assignment
		Texture(const Texture&) = delete;
		Texture& operator=(const Texture&) = delete;

		// Move constructor and assignment
		Texture(Texture&& other) noexcept;
		Texture& operator=(Texture&& other) noexcept;

		int getWidth() const;
		int getHeight() const;

		SDL_Texture* getData() const;
		void setData(SDL_Texture* texture);
		bool isValid();

	protected:
		SDL_Texture* data = nullptr;
	};

}

#endif
