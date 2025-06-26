#pragma once
#ifndef MATHCONSTANTS_H
#define MATHCONSTANTS_H

namespace CE {

    // Epsilon value used for angle comparisons (in degrees).
    // Use this to check if a rotation angle is effectively zero,
    // e.g., std::abs(angle) < ANGLE_EPSILON
    inline constexpr double NEAR_ZERO_THRESHOLD = 0.001;

    // Add more mathematical constants here as needed, e.g.:
    inline constexpr double PI = 3.14159265358979323846;
    inline constexpr double DEG_TO_RAD = PI / 180.0;

}

#endif // MATHCONSTANTS_H