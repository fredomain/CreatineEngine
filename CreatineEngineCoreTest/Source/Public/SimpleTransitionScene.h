#pragma once
#ifndef SIMPLETRANSITIONSCENE_H
#define SIMPLETRANSITIONSCENE_H

#include "TransitionScene.h"
#include "LoadingLabel.h"

class SimpleTransitionScene : public CE::TransitionScene
{
public:
	SimpleTransitionScene(std::string name);

	void initialize() override;
	void update() override;

private:
	LoadingLabel* loadingLabel;
};

#endif

