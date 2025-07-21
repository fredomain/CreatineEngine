#pragma once
#ifndef DYNAMICNUMBERTEXTUREINSTANCE_H
#define DYNAMICNUMBERTEXTUREINSTANCE_H

#include "TextureInstance.h"

namespace CE {

	/**
	 * @brief Use this class for quick changing text render.
	 * Receives a TextTexture with simbols 0-9 to
	 * generate a number texture very efficiently.
	 * For static numbers, use a TextureInstance with a TextTexture Texture.
	 */
	class DynamicNumberTextureInstance : public TextureInstance
	{


	};

}

#endif

