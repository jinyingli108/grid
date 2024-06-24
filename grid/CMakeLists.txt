# CMakeList.txt : CMake project for grid, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.29)

project ("grid")

# Language settings.
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Build configuration settings.
set(CMAKE_CONFIGURATION_TYPES "Debug" "Release")

# Compiler warning settings.
if(MSVC)
    add_compile_options("/Wall")
else()
    add_compile_options("-Wall" "-Wextra" "-pedantic")
endif()

add_library (grid STATIC
    "${PROJECT_SOURCE_DIR}/src/grid.cpp"
    "${PROJECT_SOURCE_DIR}/src/common/point.h"
    "${PROJECT_SOURCE_DIR}/src/hex_grid/axial_point.h"
    "${PROJECT_SOURCE_DIR}/src/hex_grid/axial_point_fn.cpp"
    "${PROJECT_SOURCE_DIR}/src/hex_grid/axial_point_fn.h"
    "${PROJECT_SOURCE_DIR}/src/hex_grid/hex_offset_type.h"
    "${PROJECT_SOURCE_DIR}/src/hex_grid/hex_point_fn.h"
    "${PROJECT_SOURCE_DIR}/src/hex_grid/rect_hex_grid.h"
)

# Precompiled header settings.
target_precompile_headers(grid
    PRIVATE
        <cmath>
        <cstdint>
        <cstdlib>
        <stdexcept>
        <utility>
        <vector>
)

# TODO: Add tests and install targets if needed.
