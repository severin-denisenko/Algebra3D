cmake_minimum_required(VERSION 3.24)
project(Algebra3D)

set(CMAKE_CXX_STANDARD 23)

file(GLOB SRC src/* include/Algebra3D/*)
add_library(Algebra3D ${SRC})
include_directories(include)

file(GLOB TESTS tests/*)
add_executable(Algebra3DTests ${TESTS})
target_link_libraries(Algebra3DTests Algebra3D)
