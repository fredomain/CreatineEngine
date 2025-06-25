#include "Asset.h"
#include <memory>

namespace CE {

    Asset::Asset(std::string path = "")
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