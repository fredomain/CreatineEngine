#pragma once
#ifndef FPS_DISPLAY_H
#define FPS_DISPLAY_H

#include "CreatineEngineCore.h"

class FPS_Display : public CE::Entity
{
public:
	FPS_Display(CE::Scene& scene);

	void update(float deltaTime) override;
	void initialize() override;

protected:
	std::unique_ptr<CE::TextureInstance> textureInst;
};

#endif

