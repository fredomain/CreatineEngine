#include "Image.h"

using namespace CE;

//Constructor and Destructor
Image::Image()
{
	xPos = 0;
	yPos = 0;
	width = 0;
	height = 0;
	imageTexture = NULL;
}
Image::~Image()
{
	xPos = 0;
	yPos = 0;
	width = 0;
	height = 0;
	SDL_DestroyTexture(imageTexture);
	imageTexture = NULL;
}

//Load file from path and transform it to Texture
bool Image::loadFromFile(const std::string path, SDL_Renderer* gRenderer)
{
	//TO DO
}

//Setters and Getters
int const Image::xPos()
{
	return xPos_;
}
int const Image::yPos()
{
	return yPos_;
}
int const Image::width()
{
	return width_;
}
int const Image::height()
{
	return height_;
}

void Image::xPos(int xPos)
{
	xPos_ = xPos;
}
void Image::yPos(int yPos)
{
	yPos_ = yPos;
}
void Image::width(int width)
{
	width_ = width;
}
void Image::height(int height)
{
	height_ = height;
}