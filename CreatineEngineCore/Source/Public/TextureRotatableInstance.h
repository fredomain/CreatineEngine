#pragma once
#ifndef TEXTUREROTATABLEINSTANCE_H
#define TEXTUREROTATABLEINSTANCE_H

#include "TextureInstance.h"

namespace CE {

	class TextureRotatableInstance : public TextureInstance
	{
	public:

		// Conctructors & destructor
		TextureRotatableInstance(Texture& texture);
		~TextureRotatableInstance();

		// Virtual functions
		void render() const override;
		void init() override;

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

		// Flip operations
		void setVerticalFlip();
		void setHorizontalFlip();
		void disableFlip();
		void setFlipMode(const SDL_FlipMode& mode);
		SDL_FlipMode getFlipMode() const;
		const SDL_FlipMode& getFlipModeRef() const;

	private:
		double rotation;				// Unit: degrees
		FVector rotationOrigin;			// Rotation origin (destination rect local frame)
		SDL_FlipMode flipMode;			// Only applies when rotations are enabled

	};

}

#endif

