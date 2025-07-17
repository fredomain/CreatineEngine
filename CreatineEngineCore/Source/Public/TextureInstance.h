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
		TextureInstance(std::shared_ptr<Texture> texture);
		~TextureInstance();

		// Virtual functions
		void render() const override;

	protected:
		std::shared_ptr<Texture> texture;

	private:
		static void onTextureLoaded(void* callbackObject);

	};

}

#endif

