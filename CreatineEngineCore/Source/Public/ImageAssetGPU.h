#pragma once
#ifndef IMAGEASSETGPU_H
#define IMAGEASSETGPU_H

#include "Asset.h"
#include <SDL3/SDL.h>
#include "AssetManager.h"

namespace CE {

    class ImageAssetGPU :
        public Asset
    {
    public:
        ImageAssetGPU(const std::string& path, SDL_Renderer* renderer, AssetManager* assetManager = nullptr);
        bool load() override;
    private:
        SDL_Texture* texture;
        SDL_Renderer* renderer;
    };
}

#endif // !IMAGEASSETGPU_H

