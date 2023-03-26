//
// Created by Severin on 26.03.2023.
//

#include "Algebra3D/Mat3.hpp"

namespace algebra {
    Mat3::ValueType& Mat3::operator()(std::size_t i, std::size_t j) {
        return mat[i](j);
    }

    const Mat3::ValueType& Mat3::operator()(std::size_t i, std::size_t j) const {
        return mat[i](j);
    }
} // algebra