#include "TextureAsset.h"

namespace CE {

    TextureAsset::TextureAsset(std::shared_ptr<SDL_Renderer> renderer, std::string path)
        : Asset(std::move(path)), renderer(renderer), texture(nullptr) {
    }

    void TextureAsset::setRenderer(std::shared_ptr<SDL_Renderer> renderer) {
        this->renderer = renderer;
    }

    std::shared_ptr<SDL_Renderer> TextureAsset::getRenderer() const {
        return renderer.lock();     // Convert the weak_ptr to shared_ptr if the object still exists
    }

    SDL_Texture* TextureAsset::getTexture() const {
        return texture.get();
    }

}
