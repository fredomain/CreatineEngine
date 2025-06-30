#pragma once
#ifndef TEXTURERENDER_H
#define TEXTURERENDER_H

#include "Renderable.h" //Parent header
#include "Texture.h"

namespace CE {

	class TextureRender : public Renderable
	{
	public:
		TextureRender(SDL_Renderer* renderer, std::string path, bool rotation_enabled = false);

		void render() const override;
		void init() override;

		Texture* texture;

	protected:
		void renderSimple() const;
		void renderRotated() const;
	};



}

#endif // !TEXTURERENDER_H


