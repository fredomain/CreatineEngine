
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

		/* SETTERS AND GETTERS */
		int const xPos();
		int const yPos();
		int const width();
		int const height();

		void xPos(int xPos);
		void yPos(int xPos);
		void width(int width);
		void height(int height);

	private:
		SDL_Texture* imageTexture;												//SDL Texture		

		int xPos_;																//Texture X position
		int yPos_;																//Texture Y position

		int width_;																//Texture width
		int height_;															//Texture height

	};

}

#endif // !IMAGE_H


