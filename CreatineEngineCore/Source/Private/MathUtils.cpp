#include "MathUtils.h"

namespace CE {

    FVector MathUtils::toFVector(const Vector& vec) {
        return FVector(static_cast<float>(vec.x),
            static_cast<float>(vec.y));
    }

    Vector MathUtils::toVector(const FVector& fvec) {
        return Vector(static_cast<int>(fvec.x),
            static_cast<int>(fvec.y));
    }

}
