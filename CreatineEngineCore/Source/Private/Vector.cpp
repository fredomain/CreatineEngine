#include "Vector.h"

namespace CE {

    Vector::Vector() : x(0), y(0) {}

    Vector::Vector(int x, int y) : x(x), y(y) {}

    Vector Vector::operator+(const Vector& other) const {
        return Vector{ x + other.x, y + other.y };
    }

    Vector Vector::operator-(const Vector& other) const {
        return Vector{ x - other.x, y - other.y };
    }

    Vector Vector::operator*(int scalar) const {
        return Vector{ x * scalar, y * scalar };
    }

    Vector Vector::operator/(int scalar) const {
        return Vector{ x / scalar, y / scalar };
    }

    Vector& Vector::operator+=(const Vector& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector& Vector::operator-=(const Vector& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector& Vector::operator*=(int scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector& Vector::operator/=(int scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    bool Vector::operator==(const Vector& other) const {
        return x == other.x && y == other.y;
    }

    bool Vector::operator!=(const Vector& other) const {
        return !(*this == other);
    }

    int Vector::dot(const Vector& other) const {
        return x * other.x + y * other.y;
    }

    int Vector::cross(const Vector& other) const {
        return x * other.y - y * other.x;
    }

    double Vector::length() const {
        return std::sqrt(static_cast<double>(x) * x + static_cast<double>(y) * y);
    }

    int Vector::lengthSquared() const {
        return x * x + y * y;
    }

}
