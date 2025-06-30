#include "Texture.h"

namespace CE {
	Texture::~Texture() {
		SDL_DestroyTexture(&data);
	}
	
}
