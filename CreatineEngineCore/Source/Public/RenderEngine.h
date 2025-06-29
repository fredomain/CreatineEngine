#pragma once
#ifndef RENDERENGINE_H
#define RENDERENGINE_H

#include "Renderable.h"
#include <queue>

namespace CE {

	class RenderEngine
	{
	private:
		std::queue<Renderable> renderList;

		// renderizartodo();

		addrenderable();
	};

}

#endif // !RENDERENGINE_H

