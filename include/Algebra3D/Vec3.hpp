//
// Created by Severin on 26.03.2023.
//

#ifndef ALGEBRA3D_VEC3_HPP
#define ALGEBRA3D_VEC3_HPP

#include <cstdlib>
#include <ostream>

namespace algebra {

    class Vec3 {
    public:
        using ValueType = double;

        Vec3();
        Vec3(ValueType i, ValueType j, ValueType k);

        Vec3 unit();
        ValueType norm();

        Vec3 operator-() const;
        Vec3& operator-=(const Vec3& other);
        Vec3& operator+=(const Vec3& other);
        Vec3& operator*=(ValueType other);
        Vec3& operator/=(ValueType other);

        ValueType& operator()(std::size_t index);
        const ValueType& operator()(std::size_t index) const;

        ValueType i;
        ValueType j;
        ValueType k;
    };

    inline std::ostream& operator<<(std::ostream& out, const Vec3& v) {
        return out << v.i << ' ' << v.j << ' ' << v.k;
    }

    inline Vec3 operator+(const Vec3& a, const Vec3& b) {
        return {a.i + b.i, a.j + b.j, a.k + b.k};
    }

    inline Vec3 operator-(const Vec3& a, const Vec3& b) {
        return {a.i - b.i, a.j - b.j, a.k - b.k};
    }

    inline Vec3 operator*(const Vec3& a, const Vec3& b) {
        return {a.i * b.i, a.j * b.j, a.k * b.k};
    }

    inline Vec3 operator*(Vec3::ValueType a, const Vec3& b) {
        return {a * b.i, a * b.j, a * b.k};
    }

    inline Vec3 operator*(const Vec3& a, Vec3::ValueType b) {
        return {a.i * b, a.j * b, a.k * b};
    }

    inline Vec3 operator/(Vec3 a, Vec3::ValueType b) {
        return {a.i / b, a.j / b, a.k / b};
    }

    inline Vec3::ValueType dot(const Vec3& a, const Vec3& b) {
        return a.i * b.i + a.j * b.j + a.k * b.k;
    }

    inline Vec3 cross(const Vec3& a, const Vec3& b) {
        return {a.j * b.k - a.k * b.j,
                a.k * b.i - a.i * b.k,
                a.i * b.j - a.j * b.i};
    }
} // algebra

#endif //ALGEBRA3D_VEC3_HPP
