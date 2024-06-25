cmake_minimum_required (VERSION 3.29)

project("grid_static")

add_library(grid_static STATIC
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
target_precompile_headers(grid_static
    PRIVATE
        <cmath>
        <cstdint>
        <cstdlib>
        <stdexcept>
        <utility>
        <vector>
)
