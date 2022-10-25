#include "FieldBlocks.h"

FieldBlocks::FieldBlocks(sf::RenderWindow& window) : blocks{}, window{ window }
{
	debuglog("creating field blocks");

	// todo now it only darkBlue
}
	

void FieldBlocks::draw()
{
	for (auto& el : blocks)
	{
		// TODO set color
		el.draw(window);
	}
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
	std::vector<sf::Vector2f> result;
	for (const auto& el : blocks)
	{
		result.push_back(el.getPosition());
	}
	return result;
}

void FieldBlocks::join(ActiveFigure& figure)
{
	debuglog("joining figure blocks to the field");
	auto& elements = figure.getBlocks();
	blocks.insert(std::end(blocks),
		std::begin(elements),
		std::end(elements));
}
