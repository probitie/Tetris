#pragma once
#include "libs.h"
#include "constants.h"
#include "Block.h"
#include "figure_properties.h"

#include <SFML/Graphics/RectangleShape.hpp>

class ActiveFigure
{

	// TODO THAT'S JUST FOR DEVELOPING NOT FOR ACTUAL USE
private:
	//создать тестовый квадратик на котором пока что будет
	// чекатьс яуправление и падение и падение до пола и тд
	sf::RectangleShape rectangle;


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
	/// WARNING it returns NOT a lowest block coordinates but points on bottom
	///  left side of each block (y is left the same, x' = x+block.width)
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

};

