#pragma once
#include "libs.h"
#include "constants.h"
#include "logger.h"

#include "ActiveFigure.h"

class FieldBlocks
{
private:
	sf::RenderWindow& window;
	std::shared_ptr<sf::Texture> texture;
	sf::Sprite brick;
	std::vector<Block> blocks;

public:

	FieldBlocks(sf::RenderWindow& window);

	void draw();

	const std::vector<int> getFullRowsIndexes() const;

	void deleteRowAndSqueeze(const int index);

	/// <summary>
	/// 
	/// assume u have figures like these
	///				*
	/// *    *		0
	/// 0 *  0		0
	/// 0    0 *	0
	///				
	/// so, places where is * - is the most top blocks on each line
	/// 
	/// WARNING it returns block coordinate on each line
	/// </summary>
	/// <returns></returns>
	const std::vector<sf::Vector2f> getEachTopLineCoordinates() const;

	/// <summary>
	/// active figure blocks become a part of field blocks  
	/// </summary>
	/// <param name="figure"></param>
	void join(ActiveFigure& figure);
};

