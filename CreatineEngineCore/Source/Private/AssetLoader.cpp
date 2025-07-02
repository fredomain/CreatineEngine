#include "AssetLoader.h"
#include <memory>

namespace CE {

    AssetLoader::AssetLoader(std::string path)
        : path(std::move(path)) {
    }

    void AssetLoader::load(const std::string& newPath) {
        setPath(newPath);
        load();
    }

    std::string AssetLoader::getPath() const {
        return path;
    }

    void AssetLoader::setPath(const std::string& newPath) {
        path = newPath;
    }

}