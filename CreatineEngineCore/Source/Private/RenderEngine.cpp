#include "RenderEngine.h"
#include <algorithm>
#include "Logger.h"

namespace CE {

    RenderEngine::RenderEngine(SDL_Renderer* renderer)
        : renderer(renderer) {
    }

    void RenderEngine::registerRenderable(Renderable* renderable) {
        renderList.push_back(renderable);
        needsSort = true;
    }

    void RenderEngine::unregisterRenderable(Renderable* renderable) {
        std::erase(renderList, renderable);
    }

    void RenderEngine::sortRenderListIfNeeded() {
        if (needsSort) {
            std::sort(renderList.begin(), renderList.end(),
                [](Renderable* a, Renderable* b) {
                    return a->getRenderOrder() < b->getRenderOrder();
                });
            needsSort = false;
        }
    }

    void RenderEngine::render() {
        /*
        if (viewportSet) {
            SDL_RenderSetViewport(renderer, &currentViewport);
            SDL_RenderSetScale(renderer, scaleX, scaleY);
        }
        */

        if (clearEnabled) {
            SDL_SetRenderDrawColor(renderer, clearColor.r, clearColor.g, clearColor.b, clearColor.a);
            SDL_RenderClear(renderer);
        }

        sortRenderListIfNeeded();
        Logger::log(LogFileType::Engine, std::format("{} will be rendered", renderList.size()), LogLevel::Verbose, "Render Engine");
        for (auto* renderable : renderList) {
            renderable->render();
        }

        SDL_RenderPresent(renderer);
        Logger::log(LogFileType::Engine, std::format("Screen rendered", renderList.size()), LogLevel::Verbose, "Render Engine");

        /*
        if (viewportSet) {
            SDL_RenderSetViewport(renderer, nullptr);
            SDL_RenderSetScale(renderer, 1.0f, 1.0f); // Restaurar escala
        }
        */
    }

    void RenderEngine::enableClear() {
        clearEnabled = true;
    }

    void RenderEngine::disableClear() {
        clearEnabled = false;
    }

    void RenderEngine::setClearColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
        clearColor = { r, g, b, a };
    }

    void RenderEngine::setRenderer(SDL_Renderer* newRenderer) {
        renderer = newRenderer;
    }

    SDL_Renderer* RenderEngine::getRenderer() const {
        return renderer;
    }

    // Viewport (desactivado por ahora)
    /*
    void RenderEngine::setViewportAndScale(const SDL_Rect& viewport, int logicalWidth, int logicalHeight) {
        currentViewport = viewport;
        viewportSet = true;

        // Calcular escala
        scaleX = static_cast<float>(viewport.w) / logicalWidth;
        scaleY = static_cast<float>(viewport.h) / logicalHeight;
    }

    void RenderEngine::resetViewportAndScale() {
        viewportSet = false;
    }
    */

    void RenderEngine::clear() {
        renderList.clear();
    }

}
