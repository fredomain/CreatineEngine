#include "FVector.h"

namespace CE {

    FVector::FVector() : x(0.0f), y(0.0f) {}

    FVector::FVector(float x, float y) : x(x), y(y) {}

    FVector FVector::operator+(const FVector& other) const {
        return FVector{ x + other.x, y + other.y };
    }

    FVector FVector::operator-(const FVector& other) const {
        return FVector{ x - other.x, y - other.y };
    }

    FVector FVector::operator*(float scalar) const {
        return FVector{ x * scalar, y * scalar };
    }

    FVector FVector::operator/(float scalar) const {
        return FVector{ x / scalar, y / scalar };
    }

    FVector& FVector::operator+=(const FVector& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    FVector& FVector::operator-=(const FVector& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    FVector& FVector::operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    FVector& FVector::operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    bool FVector::operator==(const FVector& other) const {
        return isEqualTo(other);
    }

    bool FVector::operator!=(const FVector& other) const {
        return !isEqualTo(other);
    }

    float FVector::dot(const FVector& other) const {
        return x * other.x + y * other.y;
    }

    float FVector::cross(const FVector& other) const {
        return x * other.y - y * other.x;
    }

    float FVector::length() const {
        return std::sqrt(x * x + y * y);
    }

    float FVector::lengthSquared() const {
        return x * x + y * y;
    }

    bool FVector::isEqualTo(const FVector& other, float epsilon) const {
        return (*this - other).lengthSquared() < (epsilon * epsilon);
    }

    FVector FVector::normalized() const {
        float len = length();
        return (len > 0.0f) ? (*this / len) : FVector{ 0.0f, 0.0f };
    }

    void FVector::normalize() {
        float len = length();
        if (len > 0.0f) {
            x /= len;
            y /= len;
        }
    }

    FVector FVector::getRotation(float radians) const {
        float cosA = std::cos(radians);
        float sinA = std::sin(radians);
        return FVector{
            x * cosA - y * sinA,
            x * sinA + y * cosA
        };
    }

    void FVector::rotate(float radians) {
        float cosA = std::cos(radians);
        float sinA = std::sin(radians);
        float newX = x * cosA - y * sinA;
        float newY = x * sinA + y * cosA;
        x = newX;
        y = newY;
    }

    float FVector::angle() const {
        // Returns the angle of this vector with respect to the positive X axis
        // Range: [-pi, pi], counterclockwise
        return std::atan2(y, x);
    }

}