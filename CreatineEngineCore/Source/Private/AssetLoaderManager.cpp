#include "AssetLoaderManager.h"
#include <print>
#include "Logger.h"

namespace CE {

    void AssetLoaderManager::registerAssetLoader(std::shared_ptr<AssetLoader> asset) {
        // Prevent duplicate paths
        /*for (const auto& existing : assetLoaderList) {
            if (existing->getPath() == asset->getPath()) {
                Logger::logMessage(LogFileType::Engine,
                    "Asset already registered",
                    LogLevel::Warn, "AssetManagment");
                return; // Already registered
            }
        }*/
        assetLoaderList.push_back(asset);
    }

    void AssetLoaderManager::loadAllAssets() const {
        for (auto& assetLoader : assetLoaderList) {
            try {
                assetLoader->load(assetLoader->getPath());
            }
            catch (const std::runtime_error&) {
                Logger::logMessage(
                    LogFileType::Engine,
                    std::format("Error loading asset: {}\n", assetLoader->getPath()),
                    LogLevel::Info,
                    "Asset Loader Manager");                    
            }
        }
    }

    int AssetLoaderManager::getTotalCount() const {
        return static_cast<int>(assetLoaderList.size());
    }

    int AssetLoaderManager::getLoadedCount() const {
        int count = 0;
        for (const auto& loader : assetLoaderList) {
            if (loader->isLoaded()) ++count;
        }
        return count;
    }

}
