#pragma once
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <vector>
#include "Resource.h"
#include "AssetLoader.h"

namespace CE {

    class ResourceManager {
    public:
        ResourceManager() = default;
        ~ResourceManager();

        void registerResource(Resource* resource);
        void unregisterResource(Resource* resource);

        void registerAssetLoader(AssetLoader* asset);
        void unregisterAssetLoader(AssetLoader* asset);
        void loadAllAssets() const;

        void clear(); // Elimina todos los recursos registrados

    private:
        std::vector<Resource*> resourceList;
        std::vector<AssetLoader*> assetLoaderList;
    };

}

#endif // RESOURCEMANAGER_H
