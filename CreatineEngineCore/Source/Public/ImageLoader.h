#pragma once
#ifndef IMAGEASSET_H
#define IMAGEASSET_H

#include "AssetLoader.h"
#include <Surface.h>
#include <memory>

namespace CE {
    class ImageLoader : public AssetLoader {
    public:

        const Surface& getSurface() const;

        bool load() override;

    protected:
        explicit ImageLoader(std::string path = "");

    };

}

#endif

