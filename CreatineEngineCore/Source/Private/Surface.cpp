#include "Surface.h"

namespace CE {
    Surface::Surface(SDL_Surface* surface) : data(surface) {}

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

    Surface::~Surface() {
        if (data) SDL_DestroySurface(data);
    }

    void Surface::load() {

    }

    bool Surface::isLoaded() const {
        return isValid();
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
        if (surface) {
            data = surface;
            observerBroadcast.notifyObservers();	// If data is set, notify observers
        }        
    }

    bool Surface::isValid() const {
        return data ? true : false;
    }
}
