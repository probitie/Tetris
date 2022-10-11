#pragma once
#include <cstdint>
#include <array>

// 2d array for simplify life
// TODO maybe it can be declared via using array2D = ...; or typedef
#define array2D(rows, cols) std::array<std::array<int, cols>, rows>


// TODO delete it and replace with smth another
struct Point
{
	int x;
	int y;
};