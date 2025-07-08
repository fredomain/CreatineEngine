#pragma once
#ifndef ASSETLOADERMANAGER_H
#define ASSETLOADERMANAGER_H

#include "AssetLoader.h"
#include <vector>
#include <memory>

namespace CE {

    class AssetLoaderManager {
    public:
        void registerAssetLoader(std::shared_ptr<AssetLoader> asset);
        void loadAllAssets() const;

        int getLoadedCount() const;
        int getTotalCount() const;

    private:
        std::vector<std::shared_ptr<AssetLoader>> assetLoaderList;
    };

}

#endif
