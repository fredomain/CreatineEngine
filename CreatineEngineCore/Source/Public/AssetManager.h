#pragma once
#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include "AssetLoader.h"
#include <vector>
#include <memory>

namespace CE {

    class AssetManager {
    public:
        void registerAssetLoader(std::shared_ptr<AssetLoader> asset);
        void loadAllAssets();

        int getLoadedCount() const;
        int getTotalCount() const;

    private:
        std::vector<std::shared_ptr<AssetLoader>> assetLoaderList;
    };

}

#endif