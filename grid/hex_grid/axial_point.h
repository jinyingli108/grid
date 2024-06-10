#pragma once

#include <cstdint>
#include <utility>

namespace grid
{
	/**
	 * A point expressed in axial coordinates.
	 */
	struct axial_point
	{
		std::int64_t q;
		std::int64_t r;

		constexpr axial_point & operator+=(axial_point const & rhs)
		{
			this->q += rhs.q;
			this->r += rhs.r;
			return *this;
		}

		constexpr axial_point & operator-=(axial_point const & rhs)
		{
			this->q -= rhs.q;
			this->r -= rhs.r;
			return *this;
		}

		friend constexpr axial_point operator+(axial_point lhs, axial_point const & rhs)
		{
			lhs += rhs;
			return lhs;
		}

		friend constexpr axial_point operator-(axial_point lhs, axial_point const & rhs)
		{
			lhs -= rhs;
			return lhs;
		}

		friend constexpr void swap(axial_point & lhs, axial_point & rhs)
		{
			using std::swap;
			swap(lhs.q, rhs.q);
			swap(lhs.r, rhs.r);
		}

		/**
		 * Get the s-coordinate.
		 * 
		 * @return The s-coordinate.
		 */
		constexpr std::int64_t get_s() const
		{
			return -q - r;
		}
	};
}
