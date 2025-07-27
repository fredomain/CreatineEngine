#pragma once
#ifndef SCENE1_H
#define SCENE1_H

#include "Scene.h"
#include "Fondo1.h"

class Scene1 : public CE::Scene
{
public:
	Scene1(std::string name);
	void initialize() override;
	void update() override;

private:
	//Event handler
	SDL_Event e;

	Fondo1* fondo;
};

#endif

