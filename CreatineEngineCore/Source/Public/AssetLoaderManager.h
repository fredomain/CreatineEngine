#pragma once
#ifndef ASSETLOADERMANAGER_H
#define ASSETLOADERMANAGER_H

#include "AssetLoader.h"
#include <vector>
#include <memory>

namespace CE {

    class AssetLoaderManager {
    public:
        void registerAssetLoader(AssetLoader* asset);
        void unregisterAssetLoader(AssetLoader* asset);
        void loadAllAssets() const;

        int getLoadedCount() const;
        int getTotalCount() const;

        void clear();

    private:
        std::vector<AssetLoader*> assetLoaderList;
    };

}

#endif
