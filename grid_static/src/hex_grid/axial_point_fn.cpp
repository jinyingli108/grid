#include "axial_point_fn.h"

#include "axial_point.h"

namespace
{
    std::size_t get_neighbor_count(std::uint64_t range)
    {
        /*
        * There are 6 * N neighbors that are exactly N units away.
        * Thus, the total number of neighbors that are within N units is 6 * summation(1 to N),
        * which simplifies to [3 * N * (N + 1)].
        */
        return 3 * range * (range + 1);
    }
}

namespace grid::hex
{
    std::vector<axial_point> get_neighbors(axial_point const & origin, std::int64_t range)
    {
        std::int64_t n = std::abs(range);
        std::size_t neighborCount = get_neighbor_count(static_cast<std::uint64_t>(n));
        std::vector<axial_point> neighbors;
        neighbors.reserve(neighborCount);

        for (std::int64_t dq = -n; dq <= n; ++dq)
        {
            for (std::int64_t dr = -dq - n; dr <= -dq + n; ++dr)
            {
                neighbors.emplace_back(origin.q + dq, origin.r + dr);
            }
        }

        return neighbors;
    }

    std::uint64_t get_distance(axial_point const & a, axial_point const & b)
    {
        axial_point delta = a - b;
        return static_cast<uint64_t>(std::abs(delta.q) + std::abs(delta.r) + std::abs(delta.q + delta.r)) / 2;
    }
}
