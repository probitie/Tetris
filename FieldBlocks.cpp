#include "FieldBlocks.h"

FieldBlocks::FieldBlocks(sf::RenderWindow& window) : blocks{}, window{ window }
{
	debuglog("creating field blocks");
	texture = std::make_shared<sf::Texture>();
	texture->loadFromFile(TEXTURE_PATH);

	brick.setTexture(*texture);
	// todo now it only darkBlue

	brick.setTextureRect(sf::IntRect(2, 2, 21, 21));
}
	

void FieldBlocks::draw()
{
	for (auto& el : blocks)
	{
		// TODO set color
		brick.setPosition(el.getPosition());
		window.draw(brick);
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
