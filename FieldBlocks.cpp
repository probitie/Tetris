#include "FieldBlocks.h"

FieldBlocks::FieldBlocks(sf::RenderWindow& window) : blockRows{}, window{ window }
{
	debuglog("creating field blocks");
	
	// init block rows
	for (int i = 0; i < TETRIS_BLOCK_AMOUNT_COL; i++)
	{
		blockRows.push_back(std::vector<Block>{});
	}

	// todo now it only darkBlue
}
	

void FieldBlocks::draw()
{
	for (auto& row : blockRows)
		for (auto& el : row)
		{

			// TODO set color
			el.draw(window);
		}
	
}

const std::vector<int> FieldBlocks::getFullRowsIndexes() const
{
	std::vector<int> res{};
	

	for (int i = 0; i < blockRows.size(); i++)
	{
		auto& row = blockRows.at(i);
		if (row.size() >= TETRIS_BLOCK_AMOUNT_ROW)
			res.push_back(i);
	}
	return res;
}

void FieldBlocks::deleteRowAndSqueeze(const int index)
{
	debuglog("deleting row " << index << " and compress field blocks");
	blockRows.at(index).clear();

	for (int i = index; i > 0; i--)
	{
		// move row down
		blockRows.at(i) = blockRows.at(i - 1);

		// move actual blocks down
		for (auto& block : blockRows.at(i))
			block.move({ 0.0f, TETRIS_BLOCK_H });
	}
}

const std::vector<sf::Vector2f> FieldBlocks::getEachTopLineCoordinates() const
{
	std::vector<sf::Vector2f> result;
	for (auto& row : blockRows)
		for (auto& el : row)
	{
		result.push_back(el.getPosition());
	}
	return result;
}

void FieldBlocks::join(ActiveFigure& figure)
{
	debuglog("joining figure blocks to the field");
	auto& elements = figure.getBlocks();
	for (int i = 0; i< blockRows.size(); i++)
	{
		auto &row = blockRows.at(i);

		for (auto& activeBlock : elements)
		{
			if (((int)activeBlock.getPosition().y) == i * TETRIS_BLOCK_H)

				row.push_back(activeBlock);

		}
	}
	return;
}
