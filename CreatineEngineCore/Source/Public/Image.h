
//ifndef to avoid errors on multiple declarations of this header
#ifndef IMAGE_H
#define IMAGE_H

#include "GPU_Surface.h" //Parent header

namespace CE {
	class Image : public GPU_Surface
	{
	public:
		Image();																//Constructor
		~Image();																//Destructor

		bool loadFromFile(const std::string path, SDL_Renderer* gRenderer);		//Load file and convert to Texture

	private:
		SDL_Texture* imageTexture;												//SDL Texture		
	};

}

#endif // !IMAGE_H


