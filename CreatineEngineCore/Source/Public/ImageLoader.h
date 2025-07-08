#pragma once
#ifndef IMAGEASSET_H
#define IMAGEASSET_H

#include "AssetLoader.h"
#include <SDL3/SDL.h>

namespace CE {

    class ImageLoader : public AssetLoader {
    public:
        using CallbackFunc = void(*)(SDL_Surface*, void*);  // Texture callback function pointer type

        // Constructors
        explicit ImageLoader(std::string path = "");        

        void setLoadCallback(CallbackFunc cb, void* callbackObject);

        void load() override;
        bool isLoaded() const override;

    private:
        CallbackFunc callback = nullptr;
        void* callbackObject = nullptr;

        SDL_Surface* surface;       // Pointer to the loaded surface. 
                                    // This class is not owner of it
                                    // but the Surface or Texture that receives the callback
    };

}

#endif

