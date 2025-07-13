#include "ResourceManager.h"
#include "Logger.h"

namespace CE {

    ResourceManager::~ResourceManager() {
        clear();
    }

    void ResourceManager::registerResource(Resource* resource) {
        if (resource && std::find(resourceList.begin(), resourceList.end(), resource) == resourceList.end()) {
            resourceList.push_back(resource);
        }
    }

    void ResourceManager::unregisterResource(Resource* resource) {
        resourceList.erase(
            std::remove(resourceList.begin(), resourceList.end(), resource),
            resourceList.end()
        );
    }

    void ResourceManager::registerAssetLoader(AssetLoader* asset) {
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

    void ResourceManager::unregisterAssetLoader(AssetLoader* asset) {
        assetLoaderList.erase(std::remove(assetLoaderList.begin(), assetLoaderList.end(), asset), assetLoaderList.end());
    }

    void ResourceManager::loadAllAssets() const {
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

    void ResourceManager::clear() {
        assetLoaderList.clear();
        for (auto* resource : resourceList) {
            if (resource) {
                delete resource; // Libera cada recurso
            }
        }
        resourceList.clear();
    }

}
