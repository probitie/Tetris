#pragma once
#include "libs.h"

/**
* manages tetramino figures
* 
* there you can 
*	- create figure
*	- set figure color
*	- set figure form
*/

namespace tetrisGame
{
	enum class TETRAMINO_COLORS;
	enum class TETRAMINO_FORMS;
	class Tetramino;

	// 4 there is an amount of blocks in each figure
	constexpr int BRICKS_IN_FIGURE = 4;

	// height expresses in blocks amount, not the coordinate height
	// ALSO, it is NOT a BRICKS_IN_FIGURE
	constexpr int FIGURE_HEIGHT = 4;

	constexpr int FIGURE_WIDTH = 2;


}
/**
* each value of the enum is an index of
* a corresponding brick texture in
* bricks texture (the image)
*/
enum class tetrisGame::TETRAMINO_COLORS
{
	darkBlue,
	violet,
	red,
	green,
	yellow,
	lightBlue,
	orange,
	blue,
	_size
};

/**
* tetramino form
*/
enum class tetrisGame::TETRAMINO_FORMS
{
	I,
	S,
	Z,
	T,
	L,
	J,
	O,
	_size
};

class tetrisGame::Tetramino
{
public:

	// tetramino needs from and first block coordinates
	// TODO also needs a color but for now it will be the same
	// for each figure
	Tetramino(TETRAMINO_FORMS form, const Vector2f &coordinates);

	// form of the tetramino (can not be changed)
	const TETRAMINO_FORMS form;

	// coordinates of the first figure block
	Vector2f coordinates;

	/**
	* creates figure (but not draws it)
	* it need to call before drawsIn method
	*/
	void createFigure();


	/**
	* changes tetramino location
	*/
	void setLocation(const Vector2f& coordinates);

	/**
	* moves tetramino on given vector with dX and dY
	*/
	void move(const Vector2f& coordinates);

	/**
	* moves tetramino on given blocks
	*/
	void move(const int blocksAmountX, const int blocksAmountY);

	/**
	* rotate on 90 degrees TODO in which direction?
	*/
	void rotate();

	/**
	* draws itself in the window object
	*/
	void drawIn(RenderWindow& window);

	/**
	* takes part from texture image that has necessary color
	*/
	void setColor(TETRAMINO_COLORS color);

	/**
	* if tetramino does not cross given coordinate with any of its parts
	* returns true
	*
	* Not always but you should not use a real max value there, it is better
	* to pass value already with substracted "epsilon"
	*	Ex:
	*		not 200 but 199
	*					   or
	*		not 1000 but 1000 - SIZE/2  (=> 990 for example)
	*		when you deal with minimal object size SIZE
	*
	* its because of float point precision
	* 
	*/
	bool canMoveLeftThan(const int x) const;

	/**
	* if tetramino does not cross given coordinate with any of its parts
	* returns true
	* 
	* Not always but you should not use a real max value there, it is better
	* to pass value already with substracted "epsilon"
	*	Ex:
	*		not 200 but 199.5
	*					   or
	*		not 1000 but 1000 - SIZE/2  (=> 990 for example)
	*		when you deal with minimal object size SIZE
	* 
	* its because of float point precision
	* 
	*/
	bool canMoveRightThan(const int x) const;

	/**
	* if tetramino 
	*	higher than ground
	*					or
	*	under it no other tetraminos
	* 
	* returns true
	*/
	// bool canMoveDown(const int groundY, ) const;


private:

	const std::string& BRICKS_TEXTURE_PATH = "C:\\Projects\\cpp\\Tetris\\images\\bricks.PNG";

	// full brick texture (actually there are 7 bricks)
	Texture brickTextureImage;

	// to simplify code, we have there only one block
	// that is used to paint ALL figures
	Sprite brick;

	// to convert our tetramino figures into coordinates, that are relative from first figure block(that can be not exist)
	std::array<Point, BRICKS_IN_FIGURE> relativeCoordinates{ 0 };

	// available figures
	array2D(7, FIGURE_HEIGHT) figures
	{
		1, 3, 5, 7, // I
		2, 4, 5, 7, // S
		3, 5, 4, 6, // Z
		3, 5, 4, 7, // T
		2, 3, 5, 7, // L
		3, 5, 7, 6, // J
		2, 3, 4, 5, // O
	};

	/**
	* translate relativeCoordinates element into real brick coordinates
	* 
	* as an element of relativeCoordinates describes order how to build bricks
	* but we need actual coordinates
	*/
	Vector2f toAbsoluteCoordinates(const Point& relative) const;
};