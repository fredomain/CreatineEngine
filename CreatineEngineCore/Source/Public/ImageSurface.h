#pragma once
#ifndef IMAGESURFACE_H
#define IMAGESURFACE_H

#include "Surface.h"
#include "ImageSurfaceGenerator.h"
#include <string>

namespace CE {

	class ImageSurface : public Surface
	{
	public: 
		ImageSurface() = delete;
		ImageSurface(std::string path);

		void load() override;

		ImageSurfaceGenerator imageSurfaceGenerator;
	};

}

#endif

