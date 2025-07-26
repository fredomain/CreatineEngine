#pragma once
#ifndef FVECTOR_H
#define FVECTOR_H

#include <cmath>

namespace CE {

    /**
     * @brief Represents a 2D vector with floating-point components and provides common vector operations.
     */
    class FVector {
    public:
        float x;
        float y;

        // Constructors
        FVector();
        FVector(float x, float y);

        // Arithmetic operators
        FVector operator+(const FVector& other) const;
        FVector operator-(const FVector& other) const;
        FVector operator*(float scalar) const;
        FVector operator/(float scalar) const;

        FVector& operator+=(const FVector& other);
        FVector& operator-=(const FVector& other);
        FVector& operator*=(float scalar);
        FVector& operator/=(float scalar);

        // Comparison operators
        bool operator==(const FVector& other) const;
        bool operator!=(const FVector& other) const;

        // Vector math
        float dot(const FVector& other) const;
        float cross(const FVector& other) const;
        float length() const;
        float lengthSquared() const;

        // Floating point comparison
        bool isEqualTo(const FVector& other, float epsilon = 1e-6f) const;

        // Normalization
        FVector normalized() const;
        void normalize();

        // Rotation
        FVector getRotation(float radians) const;
        void rotate(float radians);

        // Angle with respect to positive X axis (in radians)
        // Returns in range [-pi, pi]
        float angle() const;
    };

}

#endif // FVECTOR_H