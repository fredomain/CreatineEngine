#pragma once
#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include "Assets/Asset.h"
#include <vector>
#include <memory>

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