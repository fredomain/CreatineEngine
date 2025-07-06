#include "RenderEngine.h"

namespace CE {

    void RenderEngine::registerRenderable(Renderable* renderable) {
        renderList.push_back(renderable);
        needsSort = true; // Mark list as needing sorting
    }

    void RenderEngine::unregisterRenderable(Renderable* renderable) {
        std::erase(renderList, renderable);
        // No need to set needsSort: erasing doesn't break order
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
        sortRenderListIfNeeded();
        for (auto* renderable : renderList) {
            renderable->render();
        }
    }

} // namespace CE
