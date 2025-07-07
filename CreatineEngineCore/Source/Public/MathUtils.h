#pragma once
#ifndef MATHUTILS_H
#define MATHUTILS_H

#include "Vector.h"   // Suponiendo que defines Vector aquí
#include "FVector.h"  // Suponiendo que defines FVector aquí

namespace CE {

    class MathUtils {
    public:
        // Convierte Vector (ints) a FVector (floats)
        static FVector toFVector(const Vector& vec);

        // Convierte FVector (floats) a Vector (ints)
        static Vector toVector(const FVector& fvec);
    };

}

#endif