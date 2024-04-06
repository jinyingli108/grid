#include "pch.h"
#include "AxialPointFunctions.h"

#include "AxialPoint.h"

namespace
{
	std::size_t getNeighborCount(std::int32_t range)
	{
		/*
		* There are 6 * N neighbors that are exactly N units away.
		* Thus, the total number of neighbors that are within N units is 6 * summation(1 to N),
		* which simplifies to [3 * N * (N + 1)].
		*/
		return std::size_t{3} *range * (range + 1);
	}
}

namespace grid::hex
{
	std::vector<AxialPoint> getNeighbors(AxialPoint const & origin, std::int32_t range)
	{
		std::int32_t n = std::abs(range);
		std::size_t neighborCount = getNeighborCount(n);
		std::vector<AxialPoint> neighbors;
		neighbors.reserve(neighborCount);

		for (std::int32_t dq = -n; dq <= n; ++dq)
		{
			for (std::int32_t dr = -dq - n; dr <= -dq + n; ++dr)
			{
				neighbors.emplace_back(origin.q + dq, origin.r + dr);
			}
		}
	}

	std::uint32_t getDistance(AxialPoint const & a, AxialPoint const & b)
	{
		AxialPoint delta = a - b;
		return static_cast<uint32_t>(std::abs(delta.q) + std::abs(delta.r) + std::abs(delta.q + delta.r)) / 2;
	}
}
