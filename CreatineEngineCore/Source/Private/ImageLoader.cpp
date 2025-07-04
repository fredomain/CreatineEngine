#include "ImageLoader.h"
#include <SDL_image.h>
#include <stdexcept>

#include <print>

namespace CE {

    ImageLoader::ImageLoader(std::string path)
        : AssetLoader(std::move(path)) {
    }

    /**
     * @brief Sets the callback function to be invoked during image loading.
     * @param cb The callback function to be called during image loading.
     * @param callbackObject A pointer to the object that will be passed to the callback function.
     */
    void ImageLoader::setLoadCallback(CallbackFunc cb, void* callbackObject) {
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
            //std::print("Calling callback");
        }

        SDL_DestroySurface(surface);
    }

}
