#include "TextureAsset.h"

namespace CE {

    TextureAsset::TextureAsset(SDL_Renderer* renderer, std::string path)
        : Asset(std::move(path)), renderer(renderer), texture(nullptr) {
    }

    void TextureAsset::setRenderer(SDL_Renderer* renderer) {
        this->renderer = renderer;
    }

    SDL_Renderer* TextureAsset::getRenderer() const {
        return renderer;
    }

    SDL_Texture* TextureAsset::getTexture() const {
        return texture.get();
    }

}
