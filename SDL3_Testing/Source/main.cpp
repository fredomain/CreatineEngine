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

void drawCross(SDL_Renderer* renderer, int screenWidth, int screenHeight, float size = 20.0f)
{
	// Center of screen
	float cx = screenWidth * 0.5f;
	float cy = screenHeight * 0.5f;

	// Line endpoints
	SDL_FPoint line1Start = { cx - size * 0.5f, cy - size * 0.5f };
	SDL_FPoint line1End = { cx + size * 0.5f, cy + size * 0.5f };

	SDL_FPoint line2Start = { cx + size * 0.5f, cy - size * 0.5f };
	SDL_FPoint line2End = { cx - size * 0.5f, cy + size * 0.5f };

	// Set draw color (e.g., red)
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	// Draw two lines forming an X
	SDL_RenderLine(renderer, line1Start.x, line1Start.y, line1End.x, line1End.y);
	SDL_RenderLine(renderer, line2Start.x, line2Start.y, line2End.x, line2End.y);
}

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
		// Forma 1
		/*gHelloWorld = IMG_Load("Content/Images/background.jpg");
		if (gHelloWorld == NULL) {
			SDL_Log("Unable to load image %s! SDL Error: %s\n", "brackground.jpg", SDL_GetError());
		}
		CE::Texture imagenFondo(gRenderer, gHelloWorld);*/

		// Forma 2
		CE::ImageLoader imageLoader("Content/Images/background.jpg");
		CE::Texture imagenFondoT(gRenderer, imageLoader);
		CE::TextureInstanceRotatable imagenFondo(&imagenFondoT);
		imageLoader.load();

		// Forma 3
		/*SDL_Color color{255, 255, 0, 255};
		TTF_Font* font = TTF_OpenFont("Content/Fonts/lazy.ttf", 60);
		CE::Texture imagenFondoT(gRenderer, "Mori feo, Andres pelotudo", font, 26, color);
		CE::TextureInstanceRotatable imagenFondo(&imagenFondoT);*/
		
		imagenFondo.setPositionAnchor(CE::RectAnchor::CENTER);
		imagenFondo.init();
		imagenFondo.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		imagenFondo.setScale(0.5f);
		
		imagenFondo.setRotationOrigin(CE::RectAnchor::CENTER);
		imagenFondo.setRotation(45);
		imagenFondo.setFlipMode(SDL_FlipMode::SDL_FLIP_VERTICAL);


		//CE::Logger::setMinimumLogLevel(CE::LogLevel::Info);
		CE::Logger logger("log.txt");
		logger.log("Debug", CE::LogLevel::Debug);
		logger.log("Critical", CE::LogLevel::Critical);
		logger.log("Info", CE::LogLevel::Info);
		logger.log("Error", CE::LogLevel::Error);
		logger.log("verbose", CE::LogLevel::Verbose);
		logger.log("Warn", CE::LogLevel::Warn);
		CE::Logger::logMessage(CE::LogFileType::Engine, "Reconcha", CE::LogLevel::Warn, "Graphics");

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
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
				SDL_RenderClear(gRenderer);

				// Render texture to screen
				imagenFondo.render();
				SDL_RenderTexture(gRenderer, character_t, NULL, &character_dest);
				drawCross(gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT);

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

	TTF_Init();

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
			SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
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
