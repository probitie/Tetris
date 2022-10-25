#include "GameField.h"

GameField::GameField(sf::RenderWindow& window)
	: window{ window }, fieldBlocks{ window }, activeFigure{ window }
{
	debuglog("game field initialized");

	// when the game starts
	activeFigure.newRandowFigure();

	// todo debug
	//activeFigure.move(sf::Vector2f(42.0f, 0.0f));
	//this->fieldBlocks.join(activeFigure);
	//activeFigure.move(sf::Vector2f(-42.0f, 0.0f));

	/*bool r{};
	auto figureblocks = activeFigure.getAllBlocksCoordinates();
	auto fieldblocks = fieldBlocks.getEachTopLineCoordinates();
	for (const auto& figureBlockCoordinates : figureblocks)
		for (const auto& fieldBlockCoordinates : fieldblocks)
		{
			r = r || fieldBlockOnTheRightOfActiveFigure();
			if (r)
			{
				std::cout << r;
			}
		}

	std::cout << r;*/





}

void GameField::draw()
{
	activeFigure.draw();
	fieldBlocks.draw();
}

void GameField::moveActiveFigureRight()
{
	debuglog("move active figure right");
	const double x = activeFigure.getMostRightX();

	if (x >= TETRIS_GAMEFIELD_W)
	{
		debuglog("can not move right ( current position " << x << " is more than " << TETRIS_GAMEFIELD_W);
		return;
	}

	if (fieldBlockOnTheRightOfActiveFigure())
	{
		debuglog("can not move right, field block on the way");
		return;
	}

	activeFigure.move(sf::Vector2f(TETRIS_BLOCK_W, 0));
}

void GameField::moveActiveFigureLeft()
{
	debuglog("move active figure left");
	const double x = activeFigure.getMostLeftX();

	if (x <= TETRIS_GAMEFIELD_X)
	{
		debuglog("can not move left ( current position " << x << " is less than " << TETRIS_GAMEFIELD_X);
		return;
	}

	if (fieldBlockOnTheLeftOfActiveFigure())
	{
		debuglog("can not move left, field block on the way");
		return;
	}
	activeFigure.move(sf::Vector2f(-TETRIS_BLOCK_W, 0));

}

bool GameField::fieldBlockOnTheLeftOfActiveFigure() const
{
	auto activeblocks = activeFigure.getAllBlocksCoordinates();
	auto fieldblocks = fieldBlocks.getEachTopLineCoordinates();
	for (int active = 0; active < activeblocks.size(); active++)
		for (int field = 0; field < fieldblocks.size(); field++)
			if (areBlocksCollidedOnTheLeft(activeblocks.at(active), fieldblocks.at(field)))
				return true;
			else continue;
	return false;
}

bool GameField::fieldBlockOnTheRightOfActiveFigure() const
{
	auto figureblocks = activeFigure.getAllBlocksCoordinates();
	auto fieldblocks = fieldBlocks.getEachTopLineCoordinates();
	for (const auto& figureBlockCoordinates : figureblocks)
		for (const auto& fieldBlockCoordinates : fieldblocks)
			if (areBlocksCollidedOnTheRight(figureBlockCoordinates, fieldBlockCoordinates))
				return true;
			else continue;
	return false;
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
	auto figureblocks = activeFigure.getAllBlocksCoordinates();
	auto fieldblocks = fieldBlocks.getEachTopLineCoordinates();
	for (const auto& figureBlockCoordinates : figureblocks)
	{
		if (activeFigure.getBottomY() >= TETRIS_APP_HEIGHT)
			return true;
		for (const auto& fieldBlockCoordinates : fieldblocks)
			if (areBlocksCollided(figureBlockCoordinates, fieldBlockCoordinates))
				return true;
	}
	return false;
}

//left from first
bool GameField::areBlocksCollidedOnTheLeft(const sf::Vector2f& activeBlock, const sf::Vector2f& fieldBlock) const
{
	// first on the right, second on the left // TODO it's just fro debug purposes

	bool resX = inRange((int)activeBlock.x, (int)fieldBlock.x + TETRIS_BLOCK_W - 10, (int)fieldBlock.x + TETRIS_BLOCK_W + 10);
	bool resY = inRange(activeBlock.y, fieldBlock.y - 10, fieldBlock.y + TETRIS_BLOCK_H + 10)
		|| inRange(activeBlock.y + TETRIS_BLOCK_H, fieldBlock.y - 10, fieldBlock.y + TETRIS_BLOCK_H + 10);

	return resX && resY;

}

// right from first
bool GameField::areBlocksCollidedOnTheRight(const sf::Vector2f& activeBlock, const sf::Vector2f& fieldBlock) const
{
	bool resX = inRange((int)activeBlock.x, (int)fieldBlock.x - TETRIS_BLOCK_W - 10, (int)fieldBlock.x - TETRIS_BLOCK_W + 10);
	bool resY = inRange(activeBlock.y, fieldBlock.y - 10, fieldBlock.y + TETRIS_BLOCK_H + 10)
		|| inRange(activeBlock.y + TETRIS_BLOCK_H, fieldBlock.y - 10, fieldBlock.y + TETRIS_BLOCK_H + 10);

	return resX && resY;
}
// verticzl collision only
bool GameField::areBlocksCollided(const sf::Vector2f& activeBlock, const sf::Vector2f& fieldBlock) const
{
	return inRange(activeBlock.x, fieldBlock.x - 10, fieldBlock.x + 10)
		&& ((int)activeBlock.y + TETRIS_BLOCK_W) == (int)fieldBlock.y;
	}

bool GameField::inRange(double who, double from, double to) const
{
	auto res = from <= who && who <= to; 
	return res;
}


void GameField::resetActiveFigure()
{
	debuglog("recreate active figure");
	fieldBlocks.join(activeFigure);
	activeFigure.newRandowFigure();
}



