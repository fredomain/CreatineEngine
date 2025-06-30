#pragma once
#ifndef TEXTUREASSET_H
#define TEXTUREASSET_H

#include "Asset.h"
#include <Texture.h>
#include <memory>

namespace CE {
    class TextureAsset : public Asset {
    public:
        //virtual ~TextureAsset() = default;

        void setRenderer(SDL_Renderer* renderer);
        SDL_Renderer* getRenderer() const;

        const Texture& getTexture() const;

        virtual bool load() override;

    protected:
        explicit TextureAsset(SDL_Renderer* renderer, std::string path = "");

        Texture texture;

    private:
        SDL_Renderer* renderer = nullptr;
        
    };

}

#endif // !TEXTUREASSET_H

