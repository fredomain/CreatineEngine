#pragma once
#ifndef FONDO1_H
#define FONDO1_H

#include "CreatineEngineCore.h"

class CE::Scene;

class Fondo1 : public CE::Entity
{
public:
	Fondo1(CE::Scene& scene);

	void update(float deltaTime) override;
	void initialize() override;

	std::unique_ptr<CE::TextureInstanceRotatable> textureInst;
};

#endif
