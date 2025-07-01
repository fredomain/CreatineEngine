#include "ImageLoader.h"
#include <SDL_image.h>
#include <stdexcept>

#include <print>

namespace CE {

    ImageLoader::ImageLoader(std::string path)
        : AssetLoader(std::move(path)) {
    }

    void ImageLoader::setCallback(CallbackFunc cb, void* callbackObject) {
        callback = cb;
        this->callbackObject = callbackObject;
    }

    void ImageLoader::load() {
        SDL_Surface* surface = IMG_Load(path.c_str());
        if (!surface) {
            throw std::runtime_error(SDL_GetError());
        }

        if (callback) {
            callback(surface, callbackObject);
            std::print("Calling callback");
        }

        SDL_DestroySurface(surface);
    }

}
