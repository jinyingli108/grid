#pragma once

#include <cstdint>
#include <vector>

struct AxialPoint;

namespace grid::hex
{
	/**
	 * Get the neighboring points that are within range of the origin point.
	 * 
	 * @param[in] origin Origin point.
	 * @param[in] range Enclosing distance toRange of neighbors
	 * @return The neighboring points within range of the origin point. 
	 */
	std::vector<AxialPoint> getNeighbors(AxialPoint const & origin, std::int32_t range);

	/**
	 * Get the distance between 2 points.
	 * 
	 * @param[in] a First point.
	 * @param[in] b Second point.
	 * @return The distance between the points.
	 */
	std::uint32_t getDistance(AxialPoint const & a, AxialPoint const & b);
}
