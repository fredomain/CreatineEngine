#pragma once
#ifndef IMAGEASSET_H
#define IMAGEASSET_H

#include "AssetLoader.h"
#include <SDL3/SDL.h>

namespace CE {

    class ImageLoader : public AssetLoader {
    public:
        explicit ImageLoader(std::string path = "");

        using CallbackFunc = void(*)(SDL_Surface*, void*);

        void setLoadCallback(CallbackFunc cb, void* callbackObject);
        void load() override;        

    private:
        CallbackFunc callback = nullptr;
        void* callbackObject = nullptr;
    };

}

#endif

