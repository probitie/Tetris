#include "Tetramino.h"

namespace tetrisGame
{
}

tetrisGame::Tetramino::Tetramino(TETRAMINO_FORMS form, const Vector2f& coordinates)
	: form{ form }, coordinates { coordinates }
{
	// load texture
	brickTextureImage.loadFromFile(BRICKS_TEXTURE_PATH);

	// default color
	setColor(TETRAMINO_COLORS::darkBlue);

	// set up figure blocks
	createFigure();
}

void tetrisGame::Tetramino::createFigure()
{
	// create figure
	for (int i{ 0 }; i < FIGURE_HEIGHT; ++i)
	{
		// draw only those bricks that exist in figures array
		// ( other will be set as 0 )

		// TODO 2 is amount columns in game figure
		// example:
		//		0 0
		//		1 0
		//		1 1
		//		0 1
		//
		//  This is an "S" figure in a tetris game
		//
		//	so we have there only 2 columns and 4 rows, block index
		//	is varying from 0 to 7
		//
		//  and to get X coordinate - we need to calculate block_number(which is 0-7) % 2
		//  for 5 we will get 2 - row index
		//  and 5/2 - will get 1 - column index
		relativeCoordinates[i].x = figures[static_cast<int>(form)][i] % FIGURE_WIDTH;
		relativeCoordinates[i].y = figures[static_cast<int>(form)][i] / FIGURE_WIDTH;

	}
}

// TODO before drawIn we call this method
// (bc drawIn depends on first brick coords)
void tetrisGame::Tetramino::setLocation(const Vector2f& coordinates)
{
	this->coordinates.x = coordinates.x;
	this->coordinates.y = coordinates.y;
}

void tetrisGame::Tetramino::move(const Vector2f& coordinates)
{
	this->coordinates.x += coordinates.x;
	this->coordinates.y += coordinates.y;
}

void tetrisGame::Tetramino::move(const int blocksX, const int blocksY)
{
	move(Vector2f(
		1.0f * blocksX * BRICK_SIZE,
		1.0f * blocksY * BRICK_SIZE)
	);
}

void tetrisGame::Tetramino::rotate()
{

	// second block is a rotate center ( index 1 )
	const Point& rotateCenter = relativeCoordinates[1];

	for (auto& blockPoint : relativeCoordinates)
	{
		int dx = blockPoint.y - rotateCenter.y;
		int dy = blockPoint.x - rotateCenter.x;

		blockPoint.x = rotateCenter.x - dx;
		blockPoint.y = rotateCenter.y + dy;

	}

}

void tetrisGame::Tetramino::drawIn(RenderWindow& window)
{
	// if game field cell has value 0 - there is no brick
	// BRICKS::darkBlue - first brick color
	// BRICKS::violet - second brick color etc

	// TODO go through game field matrix and paint necessary block in
	// a real window

	// TODO move to method std::array<Point, 4> createFigure(TETRAMINO::J)

	// TODO draw all tetramino figures in other method

	// draw it on the game field
	for(int i{ 0 }; i < 4; ++i)
	{
		// use only one poor(( sprite
		// to draw our figure
		brick.setPosition(toAbsoluteCoordinates(relativeCoordinates[i]));
		window.draw(brick);
	}


	// drawGameField();
	// drawSprite(texturesSquare);
}

void tetrisGame::Tetramino::setColor(TETRAMINO_COLORS color)
{
	brick.setTexture(brickTextureImage);
	// todo now it only darkBlue
	brick.setTextureRect(IntRect(2, 2, BRICK_SIZE, BRICK_SIZE));
}

bool tetrisGame::Tetramino::canMoveLeftThan(const int x) const
{
	for (auto& el : relativeCoordinates)
	{
		auto absCoord = toAbsoluteCoordinates(el);
		if (absCoord.x < x)
		{
			return false;
		}
	}
	return true;
}

bool tetrisGame::Tetramino::canMoveRightThan(const int x) const
{
	for (auto& el : relativeCoordinates)
	{
		auto absCoord = toAbsoluteCoordinates(el);
		if (absCoord.x > x)
		{
			return false;
		}
	}
	return true;
}

Vector2f tetrisGame::Tetramino::toAbsoluteCoordinates(const Point& relative) const
{
	double x = coordinates.x + relative.x * BRICK_SIZE;
	double y = coordinates.y + relative.y * BRICK_SIZE;
	return Vector2f(x, y); // TODO maybe replace with "return {x, y};"
}
