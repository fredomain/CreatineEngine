#pragma once
#ifndef TEXTUREINSTANCE_H
#define TEXTUREINSTANCE_H

#include "Renderable.h"
#include "Texture.h"

namespace CE {

	class TextureInstance : public Renderable
	{
	public:
		// Conctructors & destructor
		TextureInstance(Texture& texture);
		~TextureInstance();

		// Virtual functions
		void render() const override;

	protected:
		Texture* texture;

	private:
		static void onTextureLoaded(void* callbackObject);

	};

}

#endif

