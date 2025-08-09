#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <concepts>  // Para conceptos estándar
#include "MathConstants.h"

namespace CE {

    /**
     * @brief 2D vector
     * @tparam T Coordinates x and y type
     */
    template <typename T>
    class Vector {
    public:
        T x{};
        T y{};

        Vector() = default;
        Vector(T x, T y) : x(x), y(y) {}

        Vector<T> operator+(const Vector<T>& other) const {
            return Vector<T>(x + other.x, y + other.y);
        }

        Vector<T> operator-(const Vector<T>& other) const {
            return Vector<T>(x - other.x, y - other.y);
        }

        template <typename S>
        Vector<T> operator*(S scalar) const {
            return Vector<T>(x * scalar, y * scalar);
        }

        template <typename S>
        Vector<T> operator/(S scalar) const {
            return Vector<T>(x / scalar, y / scalar);
        }

        Vector<T>& operator+=(const Vector<T>& other) {
            x += other.x;
            y += other.y;
            return *this;
        }

        Vector<T>& operator-=(const Vector<T>& other) {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        template <typename S>
        Vector<T>& operator*=(S scalar) {
            x *= scalar;
            y *= scalar;
            return *this;
        }

        template <typename S>
        Vector<T>& operator/=(S scalar) {
            x /= scalar;
            y /= scalar;
            return *this;
        }

        // Floating point: aproximate comparison
        bool operator==(const Vector<T>& other) const requires std::floating_point<T> {
            return (std::abs(x - other.x) < NEAR_ZERO_THRESHOLD) && (std::abs(y - other.y) < NEAR_ZERO_THRESHOLD);
        }

        // Integers: exact comparison
        bool operator==(const Vector<T>& other) const requires (!std::floating_point<T>) {
            return x == other.x && y == other.y;
        }

        bool operator!=(const Vector<T>& other) const {
            return !(*this == other);
        }

        T dot(const Vector<T>& other) const {
            return x * other.x + y * other.y;
        }

        T cross(const Vector<T>& other) const {
            return x * other.y - y * other.x;
        }

        // Funciones disponibles solo para tipos flotantes
        template<typename R = float>
        R length() const {
            return std::sqrt(x * x + y * y);
        }

        template<typename R = float>
        R lengthSquared() const {
            return x * x + y * y;
        }

        Vector<T> normalized() const requires std::floating_point<T> {
            T len = length();
            if (len == T(0)) return *this;
            return *this / len;
        }

        void normalize() requires std::floating_point<T> {
            T len = length();
            if (len != T(0)) {
                x /= len;
                y /= len;
            }
        }

        template<typename R = float>
        R angle() const {
            return std::atan2(y, x);
        }
    };

    // Alias
    using IVector = Vector<int>;
    using FVector = Vector<float>;
    using DVector = Vector<double>;

}

#endif
