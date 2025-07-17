#pragma once
#ifndef FONDO1_H
#define FONDO1_H

#include "CreatineEngineCore.h"

class CE::Scene;

class Fondo1 : public CE::Entity
{
public:
	Fondo1(CE::Scene& scene);

protected:
	CE::Scene& scene;

	static std::unique_ptr<CE::TextureInstance> texture;
};

#endif
