#pragma once
#include "libs.h"
#include "constants.h"
#include "Block.h"
#include "figure_properties.h"
#include "types.h"

#include <SFML/Graphics/RectangleShape.hpp>


class ActiveFigure
{

private:
	
	// shared ptr to one texture for all blocks
	// bloks are created when trying to draw or move them or field figure
	std::shared_ptr<sf::Texture> texture;

	// figure coordinates
	sf::Vector2f coordinates;

	// block coordinates relate to top left figure block
	// to convert our tetramino figures into coordinates, that are relative from first figure block(that can be not exist)
	std::array<Point, TETRIS_FIGURE_BLOCK_AMOUNT> relativeCoordinates{ 0 };


public:

	ActiveFigure(sf::RenderWindow& window);

	void newRandowFigure();

	/// <summary>
	/// figure coordinate will be changed on that vector
	/// </summary>
	void move(const sf::Vector2f& vector);

	/// <summary>
	/// rotate figure on 90 degrees counterclockwise
	/// </summary>
	void rotate();

	const double getMostLeftX() const;
	const double getMostRightX() const;

	/// <summary>
	/// 
	/// assume u have figures like these
	///				0
	/// 0    0		0
	/// 0 *  0		0
	/// *    * *	*
	///				
	/// so, places where is * - is the most bottom blocks on each line
	/// 
	/// WARNING it returns a lowest block coordinates (e.g a vector with all "*" coords)
	/// </summary>
	/// <returns></returns>
	const std::vector<sf::Vector2f> getEachBottomLineCoordinates() const;

	/// <summary>
	/// takes blocks from figure and gives them to u))
	/// (move semantic is here)
	/// </summary>
	const std::vector<std::unique_ptr<Block>> popBottomBlocks();

private:
	void setProperties(const FigureForm& form, const FigureColor& color, const sf::Vector2f& position);



	sf::Vector2f toAbsoluteCoordinates(const Point& relative) const;

};

