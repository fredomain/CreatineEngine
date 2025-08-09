#pragma once
#ifndef CREATINEENGINECORE_H
#define CREATINEENGINECORE_H

// SDL dependencies
#include <SDL3/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

// Graphic
#include "Surface.h"
#include "ImageSurface.h"
#include "TextSurface.h"

#include "Texture.h"
#include "ImageTexture.h"
#include "TextTexture.h"

#include "RectAnchor.h"
#include "SurfaceInstance.h"
#include "SurfaceInstanceAnimated.h"
#include "TextureInstance.h"
#include "TextureInstanceRotatable.h"
#include "TextureInstanceAnimated.h"
#include "TextureInstanceRotatableAnimated.h"

// Managers
#include "ResourceManager.h"
#include "RenderEngine.h"
#include "TimingManager.h"
#include "WindowManager.h"

// Game logic
#include "Entity.h"
#include "Scene.h"
#include "SceneManager.h"

// Math
#include "MathConstants.h"
#include "Vector.h"

// Utils
#include "Logger.h"

namespace CE {

	/**
	 * @brief Provides static methods to initialize and shut down the Creatine Engine Core. Instantiation and copying of this class are disabled.
	 */
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