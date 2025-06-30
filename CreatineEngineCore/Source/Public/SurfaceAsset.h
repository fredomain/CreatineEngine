#pragma once
#ifndef SURFACEASSET_H
#define SURFACEASSET_H

#include "Asset.h"
#include <Surface.h>
#include <memory>

namespace CE {
    class SurfaceAsset : public Asset {
    public:
        //virtual ~SurfaceAsset() = default;

        SDL_Surface* getSurface() const;

        virtual bool load() override = 0;   // Line needed to make this class abstract

    protected:
        explicit SurfaceAsset(std::string path = "");

        std::unique_ptr<Surface> surface;
    };

}

#endif // !SURFACEASSET_H

