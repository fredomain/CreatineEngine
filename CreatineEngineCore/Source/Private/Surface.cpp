#include "Surface.h"

namespace CE {
	Surface::~Surface() {
		SDL_DestroySurface(&data);
	}
}
