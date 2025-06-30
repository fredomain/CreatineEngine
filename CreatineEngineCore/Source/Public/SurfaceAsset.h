#pragma once
#ifndef SURFACEASSET_H
#define SURFACEASSET_H

#include "Asset.h"
#include <Surface.h>
#include <memory>

namespace CE {
    class SurfaceAsset : public Asset {
    public:
        //virtual ~SurfaceAsset() = default;

        const Surface& getSurface() const;

        virtual bool load() override = 0;   // Line needed to make this class abstract

    protected:
        explicit SurfaceAsset(std::string path = "");

        Surface surface;
    };

}

#endif // !SURFACEASSET_H

