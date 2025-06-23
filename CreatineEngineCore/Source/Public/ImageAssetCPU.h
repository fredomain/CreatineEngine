#pragma once
#ifndef IMAGEASSETCPU_H
#define IMAGEASSETCPU_H

#include <SDL3/SDL.h>
#include "SurfaceAsset.h"

namespace CE {

    class ImageAssetCPU :
        public SurfaceAsset
    {
        
    private:
        SDL_Surface* surface;
    };
}

#endif // !IMAGEASSETCPU_H

