#pragma once
#ifndef IMAGETEXTURE_H
#define IMAGETEXTURE_H

#include "Texture.h"
#include "ImageSurfaceGenerator.h"

namespace CE {

	class ImageTexture : public Texture
	{
	public:
		ImageTexture() = delete;
		ImageTexture(SDL_Renderer* renderer, std::string path);

		void load() override;

		ImageSurfaceGenerator imageSurfaceGenerator;
	};

}

#endif



