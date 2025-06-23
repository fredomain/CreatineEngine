#pragma once
#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <vector>
#include <memory>
#include "Asset.h"

namespace CE {

    class AssetManager {
    public:
        void registerAsset(std::shared_ptr<Asset> asset);
        void loadAllAssets();

        int getLoadedCount() const;
        int getTotalCount() const;

    private:
        std::vector<std::shared_ptr<Asset>> assets;
    };

}

#endif // !ASSETMANAGER_H