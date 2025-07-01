#pragma once
#ifndef IMAGEASSETGPU_H
#define IMAGEASSETGPU_H

#include "TextureAsset.h"

namespace CE {

    class ImageAssetGPU :
        public TextureAsset
    {
    public:
        ImageAssetGPU(SDL_Renderer* renderer, std::string path);
        bool load() override;
    };
}

#endif // !IMAGEASSETGPU_H

