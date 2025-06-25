#pragma once
#ifndef TEXTUREASSET_H
#define TEXTUREASSET_H

#include "Asset.h"
#include <SDL3/SDL.h>
#include <memory>

namespace CE {

    struct SDL_TextureDestroyer {
        void operator()(SDL_Texture* texture) const {
            if (texture) SDL_DestroyTexture(texture);
        }
    };

    class TextureAsset : public Asset {
    public:
        virtual ~TextureAsset() = default;

        void setRenderer(std::shared_ptr<SDL_Renderer> renderer);
        std::shared_ptr<SDL_Renderer> getRenderer() const;

        SDL_Texture* getTexture() const;

        virtual bool load() override = 0;

    protected:
        explicit TextureAsset(std::shared_ptr<SDL_Renderer> renderer, std::string path = "");

        std::weak_ptr<SDL_Renderer> renderer;
        std::unique_ptr<SDL_Texture, SDL_TextureDestroyer> texture;
    };

}

#endif // !TEXTUREASSET_H

