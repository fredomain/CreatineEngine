#pragma once
#ifndef IMAGE_H
#define IMAGE_H

#include "Renderable.h" //Parent header
#include "ImageAssetGPU.h"

namespace CE {

	class Image : public Renderable
	{
	public:
		Image(SDL_Renderer* renderer, std::string path);

		void render() const override;
		void init() override;

		ImageAssetGPU imageAsset;

	};

}

#endif // !IMAGE_H


