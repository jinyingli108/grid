#pragma once

namespace grid::hex
{
	/**
	 * Offset type of a horizontal hex grid.
	 * 
	 * The offset type determines whether the even or odd rows are pushed toward the +x direction when
	 * expressing a point in Cartesian coordinates.
	 */
	enum class hex_offset_type
	{
		/**
		 * Push even rows.
		 */
		even_offset = 0x0,

		/**
		 * Push odd rows.
		 */
		odd_offset = 0x1
	};
}
