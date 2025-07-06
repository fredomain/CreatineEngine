#pragma once
#ifndef SCENE_H
#define SCENE_H

#include "AssetLoaderManager.h"
#include "RenderEngine.h"
#include "TimingManager.h"

namespace CE {

	class Scene
	{
	private:
		AssetLoaderManager assetManager;
		RenderEngine renderManager;
		TimingManager timingManager;
	};

}

#endif // !SCENE_H

