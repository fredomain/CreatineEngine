#include "CreatineEngineCore.h"

namespace CE {
	void CreatineEngineCore::init() {
		// Initialize SDL
		if (!SDL_Init(SDL_INIT_VIDEO)) {
			SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		}
		else {
			TTF_Init();
		}
	}

	void CreatineEngineCore::quit() {
		// Shutdown SDL 
		TTF_Quit();
		SDL_Quit();
	}

}
