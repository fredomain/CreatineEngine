#pragma once
#ifndef IMAGESURFACEGENERATOR_H
#define IMAGESURFACEGENERATOR_H

#include "SurfaceGenerator.h"
#include <string>

namespace CE {

	class ImageSurfaceGenerator : public SurfaceGenerator
	{
	public:
		ImageSurfaceGenerator(std::string path = "");

		SDL_Surface* getSurface() const override;

		std::string getPath() const;
		void setPath(std::string path); 

	private:
		std::string path;

	};

}

#endif

