#include "AssetManager.h"
#include <print>

namespace CE {

    void AssetManager::registerAssetLoader(std::shared_ptr<AssetLoader> asset) {
        assetLoaderList.push_back(asset);
    }

    void AssetManager::loadAllAssets() {
        for (auto& assetLoader : assetLoaderList) {
            try {
                assetLoader->load(assetLoader->getPath());
            }
            catch(std::runtime_error){
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
