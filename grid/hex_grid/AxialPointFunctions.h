#pragma once

#include <cstdint>
#include <vector>

struct AxialPoint;

namespace grid::hex
{
	std::size_t getNeighborCount(std::int32_t range);
	std::vector<AxialPoint> getNeighbors(AxialPoint const & origin, std::int32_t range);
	std::uint32_t getDistance(AxialPoint const & a, AxialPoint const & b);
}
