#pragma once
#ifndef TRANSITIONSCENE_H
#define TRANSITIONSCENE_H

#include "Scene.h"

namespace CE {

    class TransitionScene : public Scene {
    private:
        Scene* targetScene = nullptr;  // Scene to be load
        //float progress = 0.0f;         // Progreso entre 0.0 y 1.0

    public:
        TransitionScene() = default;

        void setTargetScene(Scene* scene);

        void update() override;
    };

}

#endif // TRANSITIONSCENE_H
