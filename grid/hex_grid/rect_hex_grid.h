#pragma once

#include <cstdint>
#include <cstdlib>
#include <stdexcept>
#include <utility>
#include <vector>

#include "../common/point.h"

namespace grid::hex
{
	/**
	 * Rectagular hex grid which uses a horizontal (i.e. flat-top) orientation.
	 */
	template<typename Tile>
	class rect_hex_grid
	{
	public:
		using tile_type = Tile;
		using const_tile_type = Tile const;
		using index_type = common::point_2d<std::uint64_t>;

		constexpr explicit rect_hex_grid(std::vector<tile_type> && tiles, std::uint64_t width) :
			tiles(std::move(tiles))
		{
			std::lldiv_t div_result = std::div(this->tiles.size(), width);

			if (!div_result.rem)
			{
				throw std::invalid_argument("size of 'tiles' does not divide by 'width' evenly");
			}

			this->width = width;
			this->height = div_result.quot;
		}

		constexpr rect_hex_grid(rect_hex_grid const & other) :
			tiles(other.tiles), width(other.width), height(other.height)
		{}

		constexpr rect_hex_grid(rect_hex_grid && other) :
			tiles(std::move(other.tiles)), width(other.width), height(other.height)
		{}

		constexpr rect_hex_grid & operator=(rect_hex_grid const & other)
		{
			// Depend on std::vector to handle de-allocation and self-assignment.
			this->tiles = other.tiles;
			this->width = other.width;
			this->height = other.height;
			return *this;
		}

		constexpr rect_hex_grid & operator=(rect_hex_grid && other)
		{
			// Depend on std::vector to handle self-assignment.
			this->tiles = std::move(other.tiles);
			this->width = other.width;
			this->height = other.height;
			return *this;
		}

		constexpr const_tile_type & operator()(index_type index) const
		{
			return this->tiles[index.x * index.y];
		}

		constexpr tile_type & operator()(index_type index)
		{
			return const_cast<tile_type &>(const_cast<rect_hex_grid<tile_type> const *>(this)->operator()(index));
		}

		constexpr const_tile_type & get(index_type index) const
		{
			if (index.x >= this->width || index.y >= this->height)
			{
				throw std::out_of_range("out of bounds");
			}

			return operator()(index);
		}
	
		constexpr tile_type & get(index_type index)
		{
			return const_cast<tile_type &>(const_cast<rect_hex_grid<tile_type> const *>(this)->get(index));
		}

		constexpr std::uint64_t get_width() const
		{
			return this->width;
		}

		constexpr std::uint64_t get_height() const
		{
			return this->height;
		}

		friend constexpr void swap(rect_hex_grid & lhs, rect_hex_grid & rhs)
		{
			using std::swap;
			swap(lhs.tiles, rhs.tiles);
			swap(lhs.width, rhs.width);
			swap(lhs.height, rhs.height);
		}

	private:
		std::vector<tile_type> tiles;
		std::uint64_t width;
		std::uint64_t height;
	};
}
