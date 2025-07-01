#include "AssetManager.h"
#include <print>

namespace CE {

    void AssetManager::registerAssetLoader(std::shared_ptr<AssetLoader> asset) {
        assetLoaderList.push_back(asset);
    }

    void AssetManager::loadAllAssets() {
        for (auto& assetLoader : assetLoaderList) {
            if (!assetLoader->load(assetLoader->getPath())) {
                std::print("Error loading asset: {}\n", assetLoader->getPath());
            }
        }
    }

    int AssetManager::getTotalCount() const {
        return static_cast<int>(assetLoaderList.size());
    }

    int AssetManager::getLoadedCount() const {
        return static_cast<int>(assetLoaderList.size());
    }

}
