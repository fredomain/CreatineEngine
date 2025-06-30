#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL3/SDL.h>

namespace CE{
	class Texture
	{
	public:
		~Texture();		

		SDL_Texture data;
	};
}



#endif // !TEXTURERENDER_H

