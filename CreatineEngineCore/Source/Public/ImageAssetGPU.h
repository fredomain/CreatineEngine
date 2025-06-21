#pragma once
#ifndef IMAGEASSETGPU_H
#define IMAGEASSETGPU_H

#include "Asset.h"
#include <SDL3/SDL.h>

namespace CE {

    class ImageAssetGPU :
        public Asset
    {
    public:
        ImageAssetGPU(SDL_Renderer* renderer, const std::string& path, AssetManager* assetManager = nullptr);
        ImageAssetGPU(SDL_Renderer* renderer, std::string&& path, AssetManager* assetManager = nullptr);
        bool load() override;
    private:
        SDL_Texture* texture;
        SDL_Renderer* renderer;
    };
}

#endif // !IMAGEASSETGPU_H

