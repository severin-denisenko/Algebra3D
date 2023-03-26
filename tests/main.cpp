#include <iostream>

#include <Algebra3D/Vec3.hpp>
#include <Algebra3D/Mat3.hpp>

int main() {
    algebra::Vec3 vec3;

    vec3(0) = 10.0;
    vec3(1) = 11.0;
    vec3(2) = 13.0;

    algebra::Vec3 sum = vec3 + vec3;

    algebra::Mat3 mat3;

    mat3(0, 0) = 1;

    mat3 = mat3 * mat3;
    vec3 = mat3 * vec3;

    std::cout << vec3 << std::endl;

    return 0;
}
