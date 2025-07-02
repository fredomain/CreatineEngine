#pragma once
#ifndef SCENE_H
#define SCENE_H

#include "AssetManager.h"
#include "RenderEngine.h"

namespace CE {

	class Scene
	{
	private:
		AssetManager assetManager;
		RenderEngine renderManager;
	};

}

#endif // !SCENE_H

