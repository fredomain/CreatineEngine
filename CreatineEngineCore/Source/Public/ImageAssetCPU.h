#pragma once
#ifndef IMAGEASSETCPU_H
#define IMAGEASSETCPU_H

#include "Asset.h"
#include <SDL3/SDL.h>

namespace CE {

    class ImageAssetCPU :
        public Asset
    {
        
    private:
        SDL_Surface* surface;
    };
}

#endif // !IMAGEASSETCPU_H

