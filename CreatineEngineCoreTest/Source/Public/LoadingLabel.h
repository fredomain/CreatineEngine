#pragma once
#ifndef LOADINGLABEL_H
#define LOADINGLABEL_H

#include "CreatineEngineCore.h"

class CE::Scene;

class LoadingLabel : public CE::Entity
{
public:
	LoadingLabel(std::string text);

	void update(float deltaTime) override;
	void initialize() override;

	void registerComponentsInScene(CE::Scene& scene) override;

	std::unique_ptr<CE::TextureInstance> textureInst;

	TTF_Font* font;
};

#endif


