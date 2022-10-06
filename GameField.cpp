#include "GameField.h"

GameField::GameField(sf::RenderWindow& window)
	: window{ window }, fieldBlocks{ }, activeFigure{window}
{
	debuglog("game field initialized");

	// when the game starts
	activeFigure.newRandowFigure();
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
	
}

void GameField::moveActiveFigureForceDown()
{
	debuglog("move active figure to nearest block below");
}

void GameField::rotateActiveFigure()
{
	debuglog("rotate active figure on 90 degrees");
}

std::vector<int> GameField::getFullRowsIndexes()
{
	return std::vector<int>{};
}

void GameField::deleteRowAndSqueeze(int rowIndex)
{
	debuglog("deleting row " << rowIndex << " and compress field blocks");
}

bool GameField::isActiveFigureOnBottomOrFieldBlocks()
{
	return false;
}

void GameField::onLeftBound()
{
	debuglog("can not move figure left (left bound is on the left side)");
}

void GameField::onRightBound()
{
	debuglog("can not move figure right (right bound is on the right side)");
}

void GameField::joinActiveToFieldBlocks()
{
	debuglog("join active figure to field blocks");
}

void GameField::resetActiveFigure()
{
	debuglog("creating new active figure");
}
