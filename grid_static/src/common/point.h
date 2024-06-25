#pragma once

#include <cstdint>
#include <type_traits>

namespace grid::common
{
    template<typename Numeric> requires std::is_arithmetic_v<Numeric>
    struct point_2d
    {
        Numeric x;
        Numeric y;
    };

    using offset_point = point_2d<std::int64_t>;
}
