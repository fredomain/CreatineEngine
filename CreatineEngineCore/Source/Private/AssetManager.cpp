#include "AssetManager.h"
#include <print>

namespace CE {

    void AssetManager::registerAsset(std::shared_ptr<Asset> asset) {
        assets.push_back(asset);
    }

    void AssetManager::loadAllAssets() {
        for (auto& asset : assets) {
            if (!asset->load(asset->getPath())) {
                std::print("Error loading asset: {}\n", asset->getPath());
            }
        }
    }

    int AssetManager::getTotalCount() const {
        return static_cast<int>(assets.size());
    }

    int AssetManager::getLoadedCount() const {
        return static_cast<int>(assets.size());
    }

}
