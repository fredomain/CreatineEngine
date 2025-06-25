/********** INCLUDES **********/

//#include <SDL3/SDL.h>
//#include <SDL3/SDL_main.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
//#include <SDL3/SDL_version.h>
//#include <SDL_mixer.h>

#include <print>

#include "CreatineEngineCore.h"
#include <memory>
/******************************/

/********** PARAMETERS **********/
//Screen dimension constants
const uint16_t SCREEN_WIDTH = 960;
const uint16_t SCREEN_HEIGHT = 540;
/********************************/

/********** DECLARATIONS **********/
bool Init();		// Starts up SDL and creates window
bool LoadMedia();	// Loads media
void Close();		// Frees media and shuts down SDL
/**********************************/


/********** GLOBALS **********/
SDL_Window* gWindow = NULL;				// The window we'll be rendering to
SDL_Renderer* gRenderer = NULL;			//The window renderer


SDL_Surface* gHelloWorld = NULL;		// The image we will load and show on the screen
SDL_Surface* character = NULL;
SDL_Texture* gHelloWorld_t = NULL;		// The image we will load and show on the screen
SDL_Texture* character_t = NULL;

SDL_FRect character_ori;
SDL_FRect character_dest;




//Main loop flag
bool quit = false;
//Event handler
SDL_Event event;

/*****************************/

int main(int argc, char* args[]){
	//Start up SDL and create window
	if (!Init()){
		SDL_Log("Failed to initialize!\n");
	}
	else{
		//Load media
		//CE::Image* imagenFondo = new CE::Image(gRenderer, "Content/Images/background.png");
		CE::Image imagenFondo(gRenderer, "Content/Images/background.png");
		imagenFondo.imageAsset.load();
		imagenFondo.init();
		imagenFondo.enableRotation();
		imagenFondo.setRotation(0.01);

		if (!LoadMedia()){
			SDL_Log("Failed to load media!\n");
		}
		else{
			character_dest.x = 300.0f;
			character_dest.y = 120.0f;
			character_dest.w = character_t->w * 0.5f;
			character_dest.h = character_t->h * 0.5f;

			//While application is running
			while (!quit)
			{

				if (SDL_PollEvent(&event) != 0)
				{
					//User requests quit
					if (event.type == SDL_EVENT_QUIT)
					{
						quit = true;
					}
					else if (event.type == SDL_EVENT_KEY_DOWN) {
						//Select surfaces based on key press
						switch (event.key.key)
						{
						case SDLK_UP:
							character_dest.y -= 10.0f;
							break;

						case SDLK_DOWN:
							character_dest.y += 10.0f;
							break;

						case SDLK_LEFT:
							character_dest.x -= 10.0f;
							break;

						case SDLK_RIGHT:
							character_dest.x += 10.0f;
							break;
						}
					}
				}

				// Clear screen
				SDL_RenderClear(gRenderer);

				// Render texture to screen
				imagenFondo.render();
				SDL_RenderTexture(gRenderer, character_t, NULL, &character_dest);

				// Update screen
				SDL_RenderPresent(gRenderer);

				

				// Hack to get window to stay up
				//SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_EVENT_QUIT) quit = true; } }
			}
		}
	}

	//Free resources and close SDL
	Close();

	return 0;
}

bool Init(){
	bool success = true;	//Initialization flag

	//Initialize SDL
	if (!SDL_Init(SDL_INIT_VIDEO)){
		SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}else
	{
		//Create window and renderer
		if (!SDL_CreateWindowAndRenderer("SDL Tutorial", SCREEN_WIDTH, SCREEN_HEIGHT, 0, &gWindow, &gRenderer))
		{
			SDL_Log("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Initialize renderer color
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			//SDL_PropertiesID info = SDL_GetRendererProperties(gRenderer);
		}
	}

	return success;
}

bool LoadMedia(){
	// Loading success Bandera
	bool success = true;

	// Load character
	character = IMG_Load("Content/Images/character.png");
	if (character == NULL) {
		SDL_Log("Unable to load image %s! SDL Error: %s\n", "character.png", SDL_GetError());
		success = false;
	}
	else {
		//Create texture from surface pixels
		character_t = SDL_CreateTextureFromSurface(gRenderer, character);
		if (character_t == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", "character.png", SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_DestroySurface(character);
	}

	return success;
}

void Close(){
	// Deallocate surfaces
	SDL_DestroyTexture(character_t);

	// Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	// Quit SDL subsystems
	SDL_Quit();
}
