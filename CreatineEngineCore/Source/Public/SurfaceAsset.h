#pragma once
#ifndef SURFACEASSET_H
#define SURFACEASSET_H

#include "Asset.h"
#include <SDL3/SDL.h>
#include <memory>

namespace CE {

    struct SDL_SurfaceDestroyer {
        void operator()(SDL_Surface* surface) const {
            if (surface) SDL_DestroySurface(surface);
        }
    };

    class SurfaceAsset : public Asset {
    public:
        //virtual ~SurfaceAsset() = default;

        SDL_Surface* getSurface() const;

        virtual bool load() override = 0;   // Line needed to make this class abstract

    protected:
        explicit SurfaceAsset(std::string path = "");

        std::unique_ptr<SDL_Surface, SDL_SurfaceDestroyer> surface;
    };

}

#endif // !SURFACEASSET_H

