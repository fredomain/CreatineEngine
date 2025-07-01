#pragma once
#ifndef ASSETLOADER_H
#define ASSETLOADER_H

#include <string>

namespace CE {

    class AssetLoader {
    public:
        virtual ~AssetLoader() = default;

        virtual void load() = 0;    // Main load method (use internal path attribute)
        void load(const std::string& newPath);  // Set a new path and call load()

        std::string getPath() const;
        void setPath(const std::string& newPath);

    protected:
        explicit AssetLoader(std::string path = "");    // Enables derived classes to use the constructor delegation
        std::string path;
        
    };
}

#endif

