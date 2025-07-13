#pragma once
#ifndef RENDERENGINE_H
#define RENDERENGINE_H

#include <vector>
#include <SDL3/SDL.h>
#include "Renderable.h"

namespace CE {

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
        void enableClear(bool enable);                         // Activar/desactivar SDL_RenderClear
        void setClearColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a); // Cambiar color de limpieza

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
        SDL_Color clearColor{ 20, 20, 20, 255 };               // Color por defecto

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
