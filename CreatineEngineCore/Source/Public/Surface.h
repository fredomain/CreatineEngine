#pragma once
#ifndef SURFACE_H
#define SURFACE_H

#include "InstantiableResource.h"
#include <SDL3/SDL.h>

namespace CE {
    /**
     * @brief Wrapper class for SDL_Surface (CPU Image). Contains a pointer to the SDL surface data structure.
     */
    class Surface : public InstantiableResource {
    public:
        // Constructors destructors
        Surface() = default;
        explicit Surface(SDL_Surface* surface);
        ~Surface();

        Surface(const Surface&) = delete;
        Surface& operator=(const Surface&) = delete;

        Surface(Surface&& other) noexcept;
        Surface& operator=(Surface&& other) noexcept;

        void load() override;
        bool isLoaded() const override;

        SDL_Surface* getData() const;
        void setData(SDL_Surface* surface);
        bool isValid() const;

        int getWidth() const;
        int getHeight() const;

    private:
        SDL_Surface* data = nullptr;
    };

}

#endif
