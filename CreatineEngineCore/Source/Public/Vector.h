#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

namespace CE {

    /**
     * @brief Represents a 2D vector with integer components and provides arithmetic, comparison, and vector math operations.
     */
    class Vector {
    public:
        int x;
        int y;

        // Constructors
        Vector();
        Vector(int x, int y);

        // Arithmetic operators
        Vector operator+(const Vector& other) const;
        Vector operator-(const Vector& other) const;
        Vector operator*(int scalar) const;
        Vector operator/(int scalar) const;

        Vector& operator+=(const Vector& other);
        Vector& operator-=(const Vector& other);
        Vector& operator*=(int scalar);
        Vector& operator/=(int scalar);

        // Comparison operators
        bool operator==(const Vector& other) const;
        bool operator!=(const Vector& other) const;

        // Vector math
        int dot(const Vector& other) const;
        int cross(const Vector& other) const; // Result is signed scalar in 2D
        double length() const;
        int lengthSquared() const;
    };

}

#endif
