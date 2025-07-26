#pragma once
#ifndef RENDERENGINE_H
#define RENDERENGINE_H

#include <vector>
#include <SDL3/SDL.h>
#include "Renderable.h"

namespace CE {

    /**
     * @brief Manages rendering of Renderable objects using an SDL_Renderer, providing control over renderable registration, rendering, clear settings, and renderer management.
     */
    class RenderEngine {
    public:
        // Constructor
        explicit RenderEngine(SDL_Renderer* renderer);

        // Renderable management
        void registerRenderable(Renderable* renderable);
        void unregisterRenderable(Renderable* renderable);

        // Render
        void render();

        // Settings
        void enableClear();                         // Enable SDL_RenderClear
        void disableClear();                         // Enable SDL_RenderClear
        void setClearColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a); // Change clear color

        // Cambiar renderer en tiempo de ejecución (opcional)
        void setRenderer(SDL_Renderer* newRenderer);
        SDL_Renderer* getRenderer() const;

        // Viewport (desactivado por ahora)
        /*
        void setViewportAndScale(const SDL_Rect& viewport, int logicalWidth, int logicalHeight);
        void resetViewportAndScale();
        */

        void clear();

    private:
        SDL_Renderer* renderer = nullptr;                      // Renderer asociado
        std::vector<Renderable*> renderList;
        bool needsSort = false;

        bool clearEnabled = true;                               // Por defecto limpia el framebuffer
        SDL_Color clearColor{ 0, 0, 0, 255 };               // Color por defecto

        // Viewport (desactivado por ahora)
        /*
        bool viewportSet = false;          // Indica si hay un viewport activo
        SDL_Rect currentViewport{};        // Viewport actual
        float scaleX = 1.0f, scaleY = 1.0f;
        */

        void sortRenderListIfNeeded();
    };

}

#endif // RENDERENGINE_H
