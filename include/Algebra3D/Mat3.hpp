//
// Created by Severin on 26.03.2023.
//

#ifndef ALGEBRA3D_MAT3_HPP
#define ALGEBRA3D_MAT3_HPP

#include <cstdlib>

#include <Algebra3D/Vec3.hpp>

namespace algebra {

    class Mat3 {
    public:
        using ValueType = double;

        ValueType& operator()(std::size_t i, std::size_t j);
        const ValueType& operator()(std::size_t i, std::size_t j) const;

        inline friend Vec3 operator*(const Mat3& a, const Vec3& b){
            Vec3 res;

            for (int i = 0; i < 3; ++i) {
                res(i) = dot(a.mat[i], b);
            }

            return res;
        }
    private:
        Vec3 mat[3];
    };

    inline Mat3 operator*(const Mat3& a, const Mat3& b){
        Mat3 res;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    res(i, j) += a(i, k) * b(k, j);
                }
            }
        }

        return res;
    }

    inline Mat3 operator+(const Mat3& a, const Mat3& b){
        Mat3 res;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                res(i, j) += a(i, j) + b(i, j);
            }
        }

        return res;
    }

    inline Mat3 operator-(const Mat3& a, const Mat3& b){
        Mat3 res;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                res(i, j) += a(i, j) - b(i, j);
            }
        }

        return res;
    }

    inline Mat3 operator*(const Mat3& a, Mat3::ValueType b){
        Mat3 res;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                res(i, j) += a(i, j) * b;
            }
        }

        return res;
    }

    inline Mat3 operator*(Mat3::ValueType b, const Mat3& a){
        Mat3 res;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                res(i, j) += a(i, j) * b;
            }
        }

        return res;
    }
} // algebra

#endif //ALGEBRA3D_MAT3_HPP
