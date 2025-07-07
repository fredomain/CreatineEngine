#pragma once
#ifndef CREATINEENGINECORE_H
#define CREATINEENGINECORE_H

// SDL dependencies
#include <SDL3/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
//#include <SDL_mixer.h>

#include "AssetLoaderManager.h"
#include "TextureInstanceAnimated.h"
#include "TextureInstanceRotatableAnimated.h"
#include "ImageLoader.h"
#include "MathConstants.h"
#include "Logger.h"

namespace CE {

	class CreatineEngineCore
	{
		CreatineEngineCore() = delete;									// Delete default constructor
		CreatineEngineCore(const CreatineEngineCore&) = delete;				// Delete copy constructor
		CreatineEngineCore& operator=(const CreatineEngineCore&) = delete;	// Delete operator = copy

		static void init();
		static void quit();

	};

}

#endif