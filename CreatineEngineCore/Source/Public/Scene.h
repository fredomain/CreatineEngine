#pragma once
#ifndef SCENE_H
#define SCENE_H

#include "AssetLoaderManager.h"
#include "RenderEngine.h"

namespace CE {

	class Scene
	{
	private:
		AssetLoaderManager assetManager;
		RenderEngine renderManager;
	};

}

#endif // !SCENE_H

