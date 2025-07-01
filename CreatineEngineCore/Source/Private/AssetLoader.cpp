#include "AssetLoader.h"
#include <memory>

namespace CE {

    AssetLoader::AssetLoader(std::string path)
        : path(std::move(path)) {
    }

    bool AssetLoader::load(const std::string& newPath) {
        setPath(newPath);
        return load();
    }

    std::string AssetLoader::getPath() const {
        return path;
    }

    void AssetLoader::setPath(const std::string& newPath) {
        path = newPath;
    }

    void AssetLoader::setPath(std::string&& newPath) {
        path = std::move(newPath);
    }

}