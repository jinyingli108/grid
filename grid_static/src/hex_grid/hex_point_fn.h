#pragma once

#include <cstdint>

#include "../common/point.h"
#include "axial_point.h"
#include "hex_offset_type.h"

namespace grid::hex
{
    /**
     * Translate a point from axial coordinates to Cartesian coordinates.
     * 
     * @param[in] point Point in axial coordinates.
     * @return The point in axial coordinates.
     */
    template<hex_offset_type Type>
    constexpr common::offset_point to_offset_point(axial_point const & point);

    /**
     * Translate a point from Cartesian coordinates to axial coordinates.
     * 
     * @param[in] point Point in Cartesian coordinates.
     * @return The point in Cartesian coordinates.
     */
    template<hex_offset_type Type>
    constexpr axial_point to_axial_point(common::offset_point const & point);

    template<>
    constexpr common::offset_point to_offset_point<hex_offset_type::even_offset>(axial_point const & point)
    {
        std::int64_t x = point.q + (point.r + (point.r & 1)) / 2;
        std::int64_t y = point.r;
        return common::offset_point{x, y};
    }

    template<>
    constexpr common::offset_point to_offset_point<hex_offset_type::odd_offset>(axial_point const & point)
    {
        std::int64_t x = point.q + (point.r - (point.r & 1)) / 2;
        std::int64_t y = point.r;
        return common::offset_point{x, y};
    }

    template<>
    constexpr axial_point to_axial_point<hex_offset_type::even_offset>(common::offset_point const & point)
    {
        std::int64_t q = point.x - (point.y + (point.y & 1)) / 2;
        std::int64_t r = point.y;
        return axial_point{q, r};
    }

    template<>
    constexpr axial_point to_axial_point<hex_offset_type::odd_offset>(common::offset_point const & point)
    {
        std::int64_t q = point.x - (point.y - (point.y & 1)) / 2;
        std::int64_t r = point.y;
        return axial_point{q, r};
    }
}
