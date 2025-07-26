#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include <InstantiableResource.h>
#include <SDL3/SDL.h>

namespace CE {
	/**
	 * @brief Wrapper class for SDL_Texture (GPU Image). Contains a pointer to the SDL texture data structure.
	 */
	class Texture : public InstantiableResource {
	public:
		// Constructors destructors
		Texture() = default;
		explicit Texture(SDL_Renderer* renderer,
				SDL_Texture* texture
		);

		explicit Texture(SDL_Renderer* renderer,
				SDL_Surface* surface
		);
		~Texture();

		Texture(const Texture&) = delete;				// Delete copy constructor 
		Texture& operator=(const Texture&) = delete;	// and assignment

		Texture(Texture&& other) noexcept;
		Texture& operator=(Texture&& other) noexcept;

		void load() override;
		bool isLoaded() const override;

		void createFromSDL_Surface(SDL_Surface* surface);

		// Renderer operations
		void setRenderer(SDL_Renderer* renderer);
		SDL_Renderer* getRenderer() const;

		// SDL_Texture operations
		SDL_Texture* getData() const;
		void setData(SDL_Texture* texture);
		bool isValid() const;

		int getWidth() const;
		int getHeight() const;		

	private:
		SDL_Texture* data = nullptr;
		SDL_Renderer* renderer = nullptr;
		
	};

}

#endif
