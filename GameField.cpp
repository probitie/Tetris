#include "GameField.h"

GameField::GameField(sf::RenderWindow& window)
	: window{ window }, fieldBlocks{ }, activeFigure{window}
{
	debuglog("game field initialized");

	// when the game starts
	activeFigure.newRandowFigure();

}

void GameField::draw()
{
	activeFigure.draw();
	// fieldBlocks.draw();
}

void GameField::moveActiveFigureRight()
{
	debuglog("move active figure right");
	const double x = activeFigure.getMostRightX();

	if (x < TETRIS_GAMEFIELD_W)
		activeFigure.move(sf::Vector2f(TETRIS_BLOCK_W, 0));
	else
		debuglog("can not move right ( current position " << x << " is more than " << TETRIS_GAMEFIELD_W );
}

void GameField::moveActiveFigureLeft()
{
	debuglog("move active figure left");
	const double x = activeFigure.getMostLeftX();

	if (x > TETRIS_GAMEFIELD_X)
		activeFigure.move(sf::Vector2f(-TETRIS_BLOCK_W, 0));
	else
		debuglog("can not move left ( current position " << x << " is less than " << TETRIS_GAMEFIELD_X);
}

void GameField::moveActiveFigureDown()
{
	const double y = activeFigure.getBottomY();
	if(y<TETRIS_APP_HEIGHT)
		activeFigure.move(sf::Vector2f(0, TETRIS_FIGURE_VERTICAL_SPEED_PX));
}

void GameField::moveActiveFigureForceDown()
{
	debuglog("move active figure to nearest block below");
	while (!isActiveFigureOnBottomOrFieldBlocks())
		activeFigure.move(sf::Vector2f(0, TETRIS_FIGURE_VERTICAL_SPEED_PX));

}

void GameField::rotateActiveFigure()
{
	activeFigure.rotate();
}

std::vector<int> GameField::getFullRowsIndexes()
{
	return fieldBlocks.getFullRowsIndexes();
}

void GameField::deleteRowAndSqueeze(const int rowIndex)
{
	fieldBlocks.deleteRowAndSqueeze(rowIndex);
}

bool GameField::isActiveFigureOnBottomOrFieldBlocks()
{
	// if any field block lies exactly under any figure block
	// (without no space between them)
	for (const auto& figureBlockCoordinates : activeFigure.getAllBlocksCoordinates())
	{
		if (activeFigure.getBottomY() >= TETRIS_APP_HEIGHT)
			return true;
		for (const auto& fieldBlockCoordinates : fieldBlocks.getEachTopLineCoordinates())
			if (areBlocksCollided(figureBlockCoordinates, fieldBlockCoordinates))
				return true;
	}
	return false;
}

bool GameField::areBlocksCollided(const sf::Vector2f& first, const sf::Vector2f& second)
{
	auto firstXright = first.x + TETRIS_BLOCK_W;
	auto firstYright = first.y + TETRIS_BLOCK_W;


	auto secondXright = second.x + TETRIS_BLOCK_W;
	auto secondYright = second.y + TETRIS_BLOCK_W;


	auto inRange = [](auto& min, auto& max, auto& val) -> bool {
		return min <= val && val <= max;
	};

	// check X firstly (wether blocks are really one under another)
	const bool isSecondUnderFirst =
		inRange(second.x, secondXright, first.x) ||  // left point in range
		inRange(second.x, secondXright, firstXright);  //  or right point in range
		
	
	// then check their collision by Y (first block bottom crossed top of second)
	const bool isBlocksCollided =
		inRange(second.y, secondXright, first.y) ||  // left point in range
		inRange(second.y, secondXright, firstYright);  //  or right point in range

	return isSecondUnderFirst && isBlocksCollided;
}

void GameField::joinActiveToFieldBlocks()
{
	debuglog("join active figure to field blocks");
	fieldBlocks.join(activeFigure);
	resetActiveFigure();
}

void GameField::resetActiveFigure()
{
	debuglog("recreate active figure");
	activeFigure.newRandowFigure();
}



