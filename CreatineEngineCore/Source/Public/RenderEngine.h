#pragma once
#ifndef RENDERENGINE_H
#define RENDERENGINE_H

#include <vector>
#include <algorithm>
#include "Renderable.h" // Base class for all renderables

namespace CE {

    class RenderEngine {
    public:
        // Registers a new renderable and marks the list as needing sorting
        void registerRenderable(Renderable* renderable);

        // Removes a renderable from the list
        void unregisterRenderable(Renderable* renderable);

        // Sorts (if needed) and calls render() on all renderables
        void render();

    private:
        std::vector<Renderable*> renderList;
        bool needsSort = false;

        void sortRenderListIfNeeded();
    };

} // namespace CE

#endif
