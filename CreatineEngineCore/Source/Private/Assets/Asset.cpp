#include "Assets/Asset.h"
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
     * @brief General asset load function. To be replaced/overloaded by the child classes
     * @param newPath path to load the required asset (image, sound, text font...)
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
     * @brief path Setter (lvalue reference variant)
     * @param newPath string value to replace the current "path" (lvalue)
     */
    void Asset::setPath(const std::string& newPath) {
        path = newPath;
    }


    /**
     * @brief Path setter (rvalue reference variant)
     * @param newPath string value to replace the current "path" (rvalue)
     */
    void Asset::setPath(std::string&& newPath) {
        path = std::move(newPath);
    }

}