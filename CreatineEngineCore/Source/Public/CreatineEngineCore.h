#pragma once
#ifndef CREATINEENGINECORE_H
#define CREATINEENGINECORE_H

// SDL dependencies
#include <SDL3/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

// Graphic
#include "ImageLoader.h"

#include "Surface.h"
#include "Texture.h"

#include "RectAnchor.h"
#include "SurfaceInstance.h"
#include "SurfaceInstanceAnimated.h"
#include "TextureInstance.h"
#include "TextureInstanceRotatable.h"
#include "TextureInstanceAnimated.h"
#include "TextureInstanceRotatableAnimated.h"

// Managers
#include "AssetLoaderManager.h"
#include "ResourceManager.h"
#include "RenderEngine.h"
#include "TimingManager.h"
#include "WindowManager.h"

// Game logic
#include "Entity.h"
#include "Scene.h"
#include "SceneManager.h"

// Math
#include "Vector.h"
#include "FVector.h"
#include "MathUtils.h"
#include "MathConstants.h"

// Utils
#include "Logger.h"

namespace CE {

	class CreatineEngineCore
	{
	private:
		CreatineEngineCore() = delete;										// Delete default constructor
		CreatineEngineCore(const CreatineEngineCore&) = delete;				// Delete copy constructor
		CreatineEngineCore& operator=(const CreatineEngineCore&) = delete;	// Delete operator = copy

	public:
		static void init();
		static void quit();

	};

}

#endif