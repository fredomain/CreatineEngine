#include "Asset.h"
#include <memory>

namespace CE {
    /**
     * @brief Asset constructor
     * @param path : path to the Asset file (image, sound, text font...)
     */
    Asset::Asset(std::string path)
        : path(std::move(path)) {
    }

    /**
     * @brief 
     * @param newPath 
     * @return 
     */
    bool Asset::load(const std::string& newPath) {
        setPath(newPath);
        return load();
    }

    /**
     * @brief path Getter
     * @return Asset path as string
     */
    std::string Asset::getPath() const {
        return path;
    }

    /**
     * @brief path Setter
     * @param newPath string value to replace the current "path"
     */
    void Asset::setPath(const std::string& newPath) {
        path = newPath;
    }

    void Asset::setPath(std::string&& newPath) {
        path = std::move(newPath);
    }

}