#pragma once
#ifndef TEXTUREINSTANCE_H
#define TEXTUREINSTANCE_H

#include "Renderable.h"
#include "Texture.h"

namespace CE {

	class TextureInstance : public Renderable
	{
	public:
		// Virtual functions
		void render() const override;

	protected:
		Texture texture;

	};

}

#endif

