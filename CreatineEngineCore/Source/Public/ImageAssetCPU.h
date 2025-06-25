#pragma once
#ifndef IMAGEASSETCPU_H
#define IMAGEASSETCPU_H

#include <SDL3/SDL.h>
#include "SurfaceAsset.h"

namespace CE {

    class ImageAssetCPU :
        public SurfaceAsset
    {
    public:
        ImageAssetCPU(std::string path = "");
        bool load() override;
    };
}

#endif // !IMAGEASSETCPU_H

