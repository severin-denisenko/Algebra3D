//
// Created by Severin on 26.03.2023.
//

#include "Algebra3D/Vec3.hpp"

#include <cmath>

namespace algebra {
    Vec3::Vec3() : i(.0), j(.0), k(.0) {
    }

    Vec3::Vec3(Vec3::ValueType i, Vec3::ValueType j, Vec3::ValueType k) : i(i), j(j), k(k) {

    }

    Vec3 Vec3::unit() {
        ValueType n = norm();
        return {i / n, j / n, k / n};
    }

    Vec3::ValueType Vec3::norm() {
        return std::sqrt(i * i + j * j + k * k);
    }

    Vec3 Vec3::operator-() const {
        return {-i, -j, -k};
    }

    Vec3& Vec3::operator-=(const Vec3& other) {
        i -= other.i;
        j -= other.j;
        k -= other.k;

        return *this;
    }

    Vec3& Vec3::operator+=(const Vec3& other) {
        i += other.i;
        j += other.j;
        k += other.k;

        return *this;
    }

    Vec3& Vec3::operator*=(Vec3::ValueType other) {
        i *= other;
        j *= other;
        k *= other;

        return *this;
    }

    Vec3& Vec3::operator/=(Vec3::ValueType other) {
        i /= other;
        j /= other;
        k /= other;

        return *this;
    }

    Vec3::ValueType& Vec3::operator()(std::size_t index) {
        return *(reinterpret_cast<Vec3::ValueType*>(this) + index);
    }

    const Vec3::ValueType& Vec3::operator()(std::size_t index) const {
        return *(reinterpret_cast<const Vec3::ValueType*>(this) + index);
    }
} // algebra