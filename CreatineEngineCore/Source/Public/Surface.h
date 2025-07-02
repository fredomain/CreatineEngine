#pragma once
#ifndef SURFACE_H
#define SURFACE_H

#include <Renderable.h>

namespace CE {
    /**
     * @brief Wrapper class for SDL_Surface (CPU Image). Contains a pointer to the SDL surface data structure.
     */
    class Surface : public Renderable {
    public:
        Surface() = default;
        explicit Surface(SDL_Surface* surface);
        ~Surface();

        Surface(const Surface&) = delete;
        Surface& operator=(const Surface&) = delete;

        Surface(Surface&& other) noexcept;
        Surface& operator=(Surface&& other) noexcept;

        int getSDL_SurfaceWidth() const;
        int getSDL_SurfaceHeight() const;

        SDL_Surface* getData() const;
        void setData(SDL_Surface* surface);
        bool isValid();

    protected:
        SDL_Surface* data = nullptr;
    };

}

#endif
