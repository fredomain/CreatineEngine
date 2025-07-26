#pragma once
#ifndef MATHUTILS_H
#define MATHUTILS_H

#include "Vector.h"
#include "FVector.h"

namespace CE {
    class Vector;
    class FVector;

    /**
     * @brief TODO
     */
    class MathUtils {
    public:
        static FVector toFVector(const Vector& vec);
        static Vector toVector(const FVector& fvec);
    };

}

#endif