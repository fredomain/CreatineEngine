#pragma once
#ifndef SCENE2_H
#define SCENE2_H

#include "Scene.h"
#include "Fondo1.h"

class Scene2 : public CE::Scene
{
public:
	Scene2();
	void initialize() override;
	void update() override;

private:
	//Event handler
	SDL_Event e;

	Fondo1* fondo;
};

#endif