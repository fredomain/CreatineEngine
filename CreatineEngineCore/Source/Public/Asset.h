#ifndef ASSET_H
#define ASSET_H

#include <string>

namespace CE {

    class Asset
    {
    public:
        virtual bool load(const std::string& path) = 0;
        virtual std::string getPath() const = 0;
        virtual ~Asset() = default;
    };
}

#endif // !ASSET_H

