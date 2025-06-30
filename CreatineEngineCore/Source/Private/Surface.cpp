#include "Surface.h"

namespace CE {
    Surface::Surface(SDL_Surface* surface) : data(surface) {}

    Surface::~Surface() {
        if (data) SDL_DestroySurface(data);
    }

    Surface::Surface(Surface&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    Surface& Surface::operator=(Surface&& other) noexcept {
        if (this != &other) {
            if (data) SDL_DestroySurface(data);
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    int Surface::getWidth() const {
        return data ? data->w : 0;
    }

    int Surface::getHeight() const {
        return data ? data->h : 0;
    }

    SDL_Surface* Surface::getData() const {
        return data;
    }

    void Surface::setData(SDL_Surface* surface) {
        data = surface;
    }

    bool Surface::isValid() {
        return data ? true : false;
    }
}
