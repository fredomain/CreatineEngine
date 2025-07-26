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

Mix_Music* gMusic = nullptr;			// The image that will be continuously playing

Mix_Chunk* gScratch = nullptr;			// The sound effect that will be used
Mix_Chunk* gHigh = nullptr;
Mix_Chunk* gMedium = nullptr;
Mix_Chunk* gLow = nullptr;

SDL_AudioSpec* audioSpec = new SDL_AudioSpec;		// Audio specifications for SDL mixer loading

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
		CE::Texture imagenFondoT(gRenderer, gHelloWorld);
		CE::TextureInstanceRotatable imagenFondo(&imagenFondoT);
		CE::TextureInstanceRotatable imagenFondo2(&imagenFondoT);*/

		// Forma 2
		/*CE::ImageLoader imageLoader("Content/Images/background.jpg");
		CE::Texture imagenFondoT(gRenderer, imageLoader);
		CE::TextureInstanceRotatable imagenFondo(&imagenFondoT);
		CE::TextureInstanceRotatable imagenFondo2(&imagenFondoT);
		std::print("cargado: {}\n", imageLoader.isLoaded());
		imageLoader.load();
		std::print("cargado: {}\n", imageLoader.isLoaded());*/

		// Forma 3
		/*CE::AssetLoaderManager assetLoaderManager;
		//assetLoaderManager.registerAssetLoader(std::make_shared<CE::ImageLoader>("Content/Images/background.jpg"));
		auto imageLoader = std::make_shared<CE::ImageLoader>("Content/Images/background.jpg");
		assetLoaderManager.registerAssetLoader(imageLoader);

		CE::Texture imagenFondoT(gRenderer, imageLoader.get());
		CE::TextureInstanceRotatable imagenFondo(&imagenFondoT);
		CE::TextureInstanceRotatable imagenFondo2(&imagenFondoT);
		std::print("cargado: {}\n", imageLoader->isLoaded());
		//imageLoader->load();
		assetLoaderManager.loadAllAssets();
		std::print("cargado: {}\n", imageLoader->isLoaded());*/

		// Forma 4
		/*SDL_Color color{255, 255, 0, 255};
		TTF_Font* font = TTF_OpenFont("Content/Fonts/lazy.ttf", 60);
		CE::Texture imagenFondoT(gRenderer, "Mori feo, Andres pelotudo", font, 26, color);
		CE::TextureInstanceRotatable imagenFondo(&imagenFondoT);*/

		// Forma 5
		//CE::ImageTexture imagenFondoT(gRenderer, "Content/Images/background.jpg");
		CE::TextureInstanceRotatable imagenFondo(CE::ResourceManager::getImageTexture("fondo", gRenderer, "Content/Images/background.jpg"));
		CE::TextureInstanceRotatable imagenFondo2(CE::ResourceManager::getImageTexture("fondo", gRenderer, "Content/Images/background.jpg"));
		//std::print("Cargados: {}\n", assetLoaderManager.getLoadedCount());
		CE::ResourceManager::load();
		//std::print("Cargados: {}\n", assetLoaderManager.getLoadedCount());

		
		imagenFondo.setPositionAnchor(CE::RectAnchor::CENTER);
		imagenFondo.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		imagenFondo.setScale(0.5f);
		
		imagenFondo.setRotationOrigin(CE::RectAnchor::CENTER);
		imagenFondo.setRotation(45);
		imagenFondo.setFlipMode(SDL_FlipMode::SDL_FLIP_VERTICAL);

		imagenFondo2.setPositionAnchor(CE::RectAnchor::CENTER);

		imagenFondo2.setPosition(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4);
		imagenFondo2.setScale(0.2f);

		/*imagenFondo2.setRotationOrigin(CE::RectAnchor::CENTER);
		imagenFondo2.setRotation(25);
		imagenFondo2.setFlipMode(SDL_FlipMode::SDL_FLIP_HORIZONTAL);*/


		//CE::Logger::setMinimumLogLevel(CE::LogLevel::Info);
		CE::Logger logger("log.log");
		logger.log("Debug", CE::LogLevel::Debug);
		logger.log("Critical", CE::LogLevel::Critical);
		logger.log("Info", CE::LogLevel::Info);
		logger.log("Error", CE::LogLevel::Error);
		logger.log("verbose", CE::LogLevel::Verbose);
		logger.log("Warn", CE::LogLevel::Warn);
		CE::Logger::log(CE::LogFileType::Engine, "Reconcha", CE::LogLevel::Warn, "Graphics");
		CE::Logger::log(CE::LogFileType::Graphics, "Andres es muy guapo", CE::LogLevel::Info, "Texturas", CE::LogOutput::Terminal);

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
						case SDLK_1:
							printf("Reproducing scratch...\n");
							Mix_PlayChannel(-1, gHigh, 0);
							break;

						case SDLK_2:
							printf("Reproducing high sound effect...\n");
							Mix_PlayChannel(-1, gHigh, 0);
							break;

						case SDLK_3:
							printf("Reproducing medium sound effect...\n");
							Mix_PlayChannel(-1, gMedium, 0);
							break;

						case SDLK_4:
							printf("Reproducing low sound effect...\n");
							Mix_PlayChannel(-1, gLow, 0);
							break;

						case SDLK_M:
							printf("Reproducing music...\n");
							if (Mix_PausedMusic() == 1)
							{
								Mix_ResumeMusic();
							}
							else
							{
								Mix_PlayMusic(gMusic, -1);
							}
							break;

						case SDLK_P:
							printf("Pausing music...\n");
							Mix_PauseMusic();
							break;

						case SDLK_H:
							printf("Halting music...\n");
							Mix_HaltMusic();
							break;
						}
					}
				}

				// Clear screen
				//SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
				SDL_RenderClear(gRenderer);

				// Render texture to screen
				imagenFondo.render();
				imagenFondo2.render();
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

	CE::CreatineEngineCore::init();
	CE::SceneManager::initializeWindow("Creatine Engine Core Test", 640, 480, false);
	gRenderer = CE::SceneManager::getWindowRenderer();

	//TTF_Init();

	//Initialize SDL
	/*if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
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
	}*/

	//Define the audio device specifications
	audioSpec->freq = 44100;
	audioSpec->format = MIX_DEFAULT_FORMAT;
	audioSpec->channels = 2;

	// Initialize the audio device
	if (Mix_OpenAudio(0, audioSpec) < 0)
	{
		printf("SDL mixer could not initialize: %s", SDL_GetError());
		success = false;
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

	// Load music & sound files
	gMusic = Mix_LoadMUS("Content/Sounds/beat.wav");
	gScratch = Mix_LoadWAV("Content/Sounds/scratch.wav");
	gHigh = Mix_LoadWAV("Content/Sounds/high.wav");
	gMedium = Mix_LoadWAV("Content/Sounds/medium.wav");
	gLow = Mix_LoadWAV("Content/Sounds/low.wav");

	if (gMusic == NULL || gScratch == NULL || gHigh == NULL || gMedium == NULL || gLow == NULL)
	{
		printf("Failed to load audio file: %s", SDL_GetError());
		success = false;
	}

	return success;
}

void Close(){
	// Deallocate surfaces
	SDL_DestroyTexture(character_t);

	CE::CreatineEngineCore::quit();
}
