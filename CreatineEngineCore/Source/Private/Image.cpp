#include "Image.h"

using namespace CE;

//Constructor and Destructor
Image::Image()
{
	imageTexture = nullptr;
}
Image::~Image()
{
	SDL_DestroyTexture(imageTexture);
	imageTexture = nullptr;
}

//Load file from path and transform it to Texture
bool Image::loadFromFile(const std::string path, SDL_Renderer* gRenderer)
{
	//TO DO
	bool success = true;
	return success;
}