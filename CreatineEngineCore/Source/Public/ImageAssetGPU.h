#pragma once
#ifndef IMAGEASSETGPU_H
#define IMAGEASSETGPU_H

#include <SDL3/SDL.h>
#include "TextureAsset.h"

namespace CE {

    class ImageAssetGPU :
        public TextureAsset
    {
    public:
        ImageAssetGPU(SDL_Renderer* renderer, std::string path);
        bool load() override;
    private:
        SDL_Texture* texture;
        SDL_Renderer* renderer;
    };
}

#endif // !IMAGEASSETGPU_H

