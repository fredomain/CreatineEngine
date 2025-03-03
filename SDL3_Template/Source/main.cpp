/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

//Using SDL
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();
//AndresDelgado
//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
		if (gWindow == NULL)
		{
			SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success Bandera
	bool success = true;

	//Load splash image
	gHelloWorld = SDL_LoadBMP("Content/Images/hello_world.bmp");
	if (gHelloWorld == NULL)
	{
		SDL_Log("Unable to load image %s! SDL Error: %s\n", "hello_world.bmp", SDL_GetError());
		success = false;
	}

	return success;
}

void close()
{
	//Deallocate surface
	SDL_DestroySurface(gHelloWorld);
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		SDL_Log("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			SDL_Log("Failed to load media!\n");
		}
		else
		{
			//Apply the image
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

			//Update the surface
			SDL_UpdateWindowSurface(gWindow);

			//Hack to get window to stay up
			SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_EVENT_QUIT) quit = true; } }
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
