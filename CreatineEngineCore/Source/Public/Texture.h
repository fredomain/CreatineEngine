#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include <Renderable.h>
#include "ImageLoader.h"
#include <unordered_map>

namespace CE {
	/**
	 * @brief Wrapper class for SDL_Texture (GPU Image). Contains a pointer to the SDL texture data structure.
	 */
	class Texture {
	public:
		using UpdateCallback = void(*)(void* callbackObject);		// Texture Instance callback function pòinter type

		class ObserverInfo {
		public:
			ObserverInfo(UpdateCallback cb, void* obj)
				: cb(cb), callbackObject(obj) {
			}

			void notify() const {
				if (cb) cb(callbackObject);
			}

			UpdateCallback cb;
			void* callbackObject;
		};

		// Constructors destructors
		//Texture() = default;
		Texture(SDL_Renderer* renderer,
				SDL_Texture* texture
		);

		Texture(SDL_Renderer* renderer,
				SDL_Surface* surface
		);

		Texture(SDL_Renderer* renderer,
				ImageLoader& imageLoader
		);
		Texture(SDL_Renderer* renderer,
			std::string text,
			TTF_Font* font,
			size_t textSize,
			SDL_Color textColor
		);
		~Texture();

		Texture(const Texture&) = delete;				// Delete copy constructor 
		Texture& operator=(const Texture&) = delete;	// and assignment

		Texture(Texture&& other) noexcept;
		Texture& operator=(Texture&& other) noexcept;

		void createFromString(std::string text, TTF_Font* font, size_t textSize, SDL_Color textColor);
		void createFromSDL_Surface(SDL_Surface* surface);

		// Functions called by observers
		void addUpdateCallback(UpdateCallback cb, void* callbackObject);
		void removeUpdateCallback(void* callbackObject);

		// Renderer operations
		void setRenderer(SDL_Renderer* renderer);
		SDL_Renderer* getRenderer() const;

		// SDL_Texture operations
		SDL_Texture* getData() const;
		void setData(SDL_Texture* texture);
		bool isValid();

		int getWidth() const;
		int getHeight() const;

	protected:
		SDL_Texture* data = nullptr;
		SDL_Renderer* renderer = nullptr;

	private:
		static void onSurfaceLoaded(SDL_Surface* surf, void* userData);		// Function called by an assigned ImageLoader

		std::unordered_map<void*, UpdateCallback> observerMap;
		
	};

}

#endif
