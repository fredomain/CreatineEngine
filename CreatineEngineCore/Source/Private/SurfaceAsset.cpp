#include "SurfaceAsset.h"

namespace CE {

    SurfaceAsset::SurfaceAsset(std::string path = "")
        : Asset(std::move(path)), surface(nullptr) {
        surface = nullptr;
    }

    SDL_Surface* SurfaceAsset::getSurface() const {
        return surface.get();
    }

}
