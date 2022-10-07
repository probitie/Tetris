#include "FieldBlocks.h"

FieldBlocks::FieldBlocks()
{
}

void FieldBlocks::draw()
{
}

const std::vector<int> FieldBlocks::getFullRowsIndexes() const
{
	return std::vector<int>();
}

void FieldBlocks::deleteRowAndSqueeze(const int index)
{
	debuglog("deleting row " << index << " and compress field blocks");
}

const std::vector<sf::Vector2f> FieldBlocks::getEachTopLineCoordinates() const
{
	return std::vector<sf::Vector2f>();
}

void FieldBlocks::join(ActiveFigure& figure)
{
}
