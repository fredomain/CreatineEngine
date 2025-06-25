#pragma once
#ifndef SCENE_H
#define SCENE_H

#include "AssetManager.h"
#include "RenderManager.h"

namespace CE {

	class Scene
	{
	private:
		AssetManager assetManager;
		RenderManager renderManager;
	};

}

#endif // !SCENE_H

