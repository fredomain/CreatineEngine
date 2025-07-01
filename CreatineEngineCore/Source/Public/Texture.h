#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include <Renderable.h>
#include "ImageLoader.h"

namespace CE {
	/**
	 * @brief Wrapper class for SDL_Texture (GPU Image). Contains a pointer to the SDL texture data structure.
	 */
	class Texture : public Renderable{
	public:
		// Constructors destructors
		//Texture() = default;
		Texture(SDL_Renderer* renderer,
				SDL_Texture* texture,
				float rotationEnabled = false,
				double rotation = 0.0,
				FVector rotationOrigin = FVector(0.0f, 0.0f),
				SDL_FlipMode flipMode = SDL_FlipMode::SDL_FLIP_NONE
		);
		Texture(SDL_Renderer* renderer,
				SDL_Surface* surface,
				float rotationEnabled = false,
				double rotation = 0.0,
				FVector rotationOrigin = FVector(0.0f, 0.0f),
				SDL_FlipMode flipMode = SDL_FlipMode::SDL_FLIP_NONE
		);

		Texture(SDL_Renderer* renderer,
				ImageLoader* imageLoader,
				float rotationEnabled = false,
				double rotation = 0.0,
				FVector rotationOrigin = FVector(0.0f, 0.0f),
				SDL_FlipMode flipMode = SDL_FlipMode::SDL_FLIP_NONE
		);
		/*Texture(SDL_Renderer* renderer,
			std::string string,
			float rotationEnabled = false,
			double rotation = 0.0,
			FVector rotationOrigin = FVector(0.0f, 0.0f),
			SDL_FlipMode flipMode = SDL_FlipMode::SDL_FLIP_NONE
		);*/
		~Texture();

		Texture(const Texture&) = delete;				// Delete copy constructor 
		Texture& operator=(const Texture&) = delete;	// and assignment

		Texture(Texture&& other) noexcept;
		Texture& operator=(Texture&& other) noexcept;

		// Virtual functions
		void render() const override;
		void createFromSDL_Surface(SDL_Surface* surface);
		void createFromString(std::string string);
		void init() override;

		// Renderer operations
		void setRenderer(SDL_Renderer* renderer);
		SDL_Renderer* getRenderer() const;

		// SDL_Texture operations
		SDL_Texture* getData() const;
		void setData(SDL_Texture* texture);
		bool isValid();

		int getSDL_TextureWidth() const;
		int getSDL_TextureHeight() const;

		// Rotation operations
		double getRotation() const;
		void setRotation(double rotation);
		void setRotationOrigin(float x, float y);
		void setRotationOrigin(FVector rotationOrigin);
		void setRotationOrigin(RectAnchor rotationAnchor);
		float getRotationOriginX() const;
		float getRotationOriginY() const;
		FVector getRotationOrigin() const;
		SDL_FPoint getRotationOriginSDL() const;

		void enableRotation();
		void disableRotation();
		bool isRotationEnabled() const;

		// Flip operations
		void setVerticalFlip();
		void setHorizontalFlip();
		void disableFlip();
		void setFlipMode(const SDL_FlipMode& mode);
		SDL_FlipMode getFlipMode() const;
		const SDL_FlipMode& getFlipModeRef() const;

	protected:
		void renderSimple() const;
		void renderRotated() const;

		SDL_Texture* data = nullptr;

	private:
		SDL_Renderer* renderer = nullptr;

		bool rotationEnabled;			// Set false for an slight gain in performance if rotations are not needed
		double rotation;				// Unit: degrees
		FVector rotationOrigin;			// Rotation origin (destination rect local frame)
		SDL_FlipMode flipMode;			// Only applies when rotations are enabled
		
	};

}

#endif
