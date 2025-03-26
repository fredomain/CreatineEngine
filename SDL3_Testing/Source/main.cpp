/********** INCLUDES **********/

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
//#include <SDL_mixer.h>

#include <print>
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
SDL_Surface* gScreenSurface = NULL;		// The surface contained by the window
SDL_Surface* gHelloWorld = NULL;		// The image we will load and show on the screen
SDL_Surface* character = NULL;
SDL_Rect character_ori;
SDL_Rect character_dest;
/*****************************/

int main(int argc, char* args[]){
	//Start up SDL and create window
	if (!Init()){
		SDL_Log("Failed to initialize!\n");
	}
	else{
		//Load media
		if (!LoadMedia()){
			SDL_Log("Failed to load media!\n");
		}
		else{
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);


			character_ori.x = 20;
			character_ori.y = 40;
			character_ori.w = 180;
			character_ori.h = 120;
			character_dest.x = 300;
			character_dest.y = 120;

			SDL_BlitSurface(character, &character_ori, gScreenSurface, &character_dest);

			SDL_UpdateWindowSurface(gWindow);	//Update the surface

			//Hack to get window to stay up
			SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_EVENT_QUIT) quit = true; } }
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
	}
	else{
		//Create window
		gWindow = SDL_CreateWindow("SDL Testing", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
		if (gWindow == NULL){ 
			SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else{
			gScreenSurface = SDL_GetWindowSurface(gWindow);	//Get window surface
		}
	}

	return success;
}

bool LoadMedia(){
	// Loading success Bandera
	bool success = true;

	// Load splash image
	gHelloWorld = IMG_Load("Content/Images/background.png");
	if (gHelloWorld == NULL){
		SDL_Log("Unable to load image %s! SDL Error: %s\n", "background.png", SDL_GetError());
		success = false;
	}

	// Load character
	character = IMG_Load("Content/Images/character.png");
	if (character == NULL) {
		SDL_Log("Unable to load image %s! SDL Error: %s\n", "character.png", SDL_GetError());
		success = false;
	}

	return success;
}

void Close(){
	// Deallocate surfaces
	SDL_DestroySurface(gHelloWorld);
	SDL_DestroySurface(gScreenSurface);

	// Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	// Quit SDL subsystems
	SDL_Quit();
}
