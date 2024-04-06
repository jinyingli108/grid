#pragma once

#include <cstdint>
#include <utility>

namespace grid
{
	/*
	* A point expressed in axial coordinates.
	*/
	struct AxialPoint
	{
		std::int32_t q;
		std::int32_t r;

		constexpr AxialPoint & operator+=(AxialPoint const & rhs)
		{
			this->q += rhs.q;
			this->r += rhs.r;
			return *this;
		}

		constexpr AxialPoint & operator-=(AxialPoint const & rhs)
		{
			this->q -= rhs.q;
			this->r -= rhs.r;
			return *this;
		}

		friend constexpr AxialPoint operator+(AxialPoint lhs, AxialPoint const & rhs)
		{
			lhs += rhs;
			return lhs;
		}

		friend constexpr AxialPoint operator-(AxialPoint lhs, AxialPoint const & rhs)
		{
			lhs -= rhs;
			return lhs;
		}

		friend constexpr void swap(AxialPoint & lhs, AxialPoint & rhs)
		{
			using std::swap;
			swap(lhs.q, rhs.q);
			swap(lhs.r, rhs.r);
		}

		std::int32_t getS() const
		{
			return -q - r;
		}
	};
}
