#pragma once

#include <cstdint>
#include <vector>

struct axial_point;

namespace grid::hex
{
	/**
	 * Get the neighboring points that are within range of the origin point.
	 * 
	 * @param[in] origin Origin point.
	 * @param[in] range Enclosing distance toRange of neighbors
	 * @return The neighboring points within range of the origin point. 
	 */
	std::vector<axial_point> get_neighbors(axial_point const & origin, std::int64_t range);

	/**
	 * Get the distance between 2 points.
	 * 
	 * @param[in] a First point.
	 * @param[in] b Second point.
	 * @return The distance between the points.
	 */
	std::uint64_t getDistance(axial_point const & a, axial_point const & b);
}
