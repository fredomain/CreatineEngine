#pragma once
#ifndef ASSETLOADER_H
#define ASSETLOADER_H

#include <string>

namespace CE {

    class AssetLoader {
    public:
        //virtual ~Asset() = default;
        virtual bool load() = 0;    // Main load method (use internal path attribute)
        bool load(const std::string& newPath);  // Set a new path and call load()

        std::string getPath() const;
        void setPath(const std::string& newPath);
        void setPath(std::string&& newPath);

    protected:
        explicit AssetLoader(std::string path = "");    // Enables derived classes to use the constructor delegation
    

    private:
        std::string path;
    };
}

#endif

