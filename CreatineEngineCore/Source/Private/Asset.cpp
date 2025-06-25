#include "Asset.h"
#include <memory>

namespace CE {

    Asset::Asset(const std::string& path, AssetManager* assetManager)
        : path(path) {
        if (assetManager != nullptr) {
            assetManager->registerAsset(std::shared_ptr<Asset>(this));
        }
    }

    Asset::Asset(std::string&& path, AssetManager* assetManager = nullptr)
        : path(std::move(path)) {

    }

    bool Asset::load(const std::string& newPath) {
        setPath(newPath);
        return load();
    }

    std::string Asset::getPath() const {
        return path;
    }

    void Asset::setPath(const std::string& newPath) {
        path = newPath;
    }

    void Asset::setPath(std::string&& newPath) {
        path = std::move(newPath);
    }

}