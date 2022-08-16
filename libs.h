#pragma once

/**
	all other libraries, defines, constants and other project stuff
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <array>
#include <iostream>


using namespace sf;




namespace tetrisGame
{

	// 2d array for simplify life
	// TODO maybe it can be declared via using array2D = ...; or typedef
#define array2D(rows, cols) std::array<std::array<int, cols>, rows>

	// size of each brick - height and width
	constexpr int BRICK_SIZE = 21;

	// count of rows and columns on a game field
	constexpr int GAMEFIELD_ROWS = 20;
	constexpr int GAMEFIELD_COLS = 10;

	// game field size in pixels (not an actual window)
	constexpr int GAMEFIELD_WIDTH = GAMEFIELD_COLS * BRICK_SIZE;
	constexpr int GAMEFIELD_HEIGHT = GAMEFIELD_ROWS * BRICK_SIZE;

	// for window size
	constexpr int APP_WIDTH = GAMEFIELD_COLS * BRICK_SIZE;
	constexpr int APP_HEIGHT = GAMEFIELD_ROWS * BRICK_SIZE;


	// TODO delete it and replace with smth another
	struct Point
	{
		int x;
		int y;
	};



}
