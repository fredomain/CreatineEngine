#pragma once
#ifndef IMAGE_H
#define IMAGE_H

#include "Renderable.h" //Parent header
#include "Assets/ImageAssetGPU.h"

namespace CE {

	class Image : public Renderable
	{
	public:
		Image(SDL_Renderer* renderer, std::string path, bool rotation_enabled = false);

		void render() const override;
		void init() override;

		ImageAssetGPU imageAsset;

	protected:
		void renderSimple() const;
		void renderRotated() const;
	};



}

#endif // !IMAGE_H


