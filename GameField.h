#pragma once
#include "libs.h"
#include "constants.h"
#include "logger.h"

#include "ActiveFigure.h"
#include "FieldBlocks.h"

class GameField
{
private:

	sf::RenderWindow& window;

	// current tetramino
	ActiveFigure activeFigure;

	// blocks that are left from previous tetraminos
	FieldBlocks fieldBlocks;

public:

	void draw();

	/// <summary>
	/// Gamefield on a startup is without an active tetramino and with empty field blocks.
	///  You should initialize the active tetramino implicitly
	/// </summary>
	GameField(sf::RenderWindow& window);

	/// <summary>
	/// Moves current tetramino to the right 
	/// on a step, specified in constants
	/// 
	/// (like when user presses a right button)
	/// </summary>
	void moveActiveFigureRight();

	/// <summary>
	/// Moves current tetramino to the left 
	/// on a step, specified in constants
	/// 
	/// (like when user presses a left button)
	/// </summary>
	void moveActiveFigureLeft();

	/// <summary>
	/// Moves current tetramino to the bottom 
	/// on a step, specified in constants
	/// 
	/// (like when tetramino fall down)
	/// </summary>
	void moveActiveFigureDown();

	/// <summary>
	/// Moves current tetramino to the nearest bottom block
	/// (e.g. to the field figure)
	/// </summary>	
	void moveActiveFigureForceDown();

	bool fieldBlockOnTheLeftOfActiveFigure() const;
	bool fieldBlockOnTheRightOfActiveFigure() const;

	bool areBlocksCollidedOnTheLeft(const sf::Vector2f& first, const sf::Vector2f& second) const;

	bool areBlocksCollidedOnTheRight(const sf::Vector2f& first, const sf::Vector2f& second) const;

	bool inRange(double who, double from, double to) const;

	/// <summary>
	/// rotates current tetramino on 90d counterclockwise
	/// (calls the same method from ActiveFigure)
	/// </summary>	
	void rotateActiveFigure();

	/// <summary>
	/// return rows that are full of blocks
	/// 
	/// row count starts from the top block
	/// (one block can represent a first row as well as several blocks,
	///  but space from the top row can be without any block,
	///  and they will be considered as rows till you explicitly
	///  squeeze them by calling a special method)
	/// </summary>
	std::vector<int> getFullRowsIndexes();

	/// <summary>
	/// deletes empty rows(without any block)
	/// between top row and bottom screen side
	/// </summary>
	/// <param name="rowIndex"> index of that row (top row has index 0)</param>
	void deleteRowAndSqueeze(const int rowIndex);

	/// <summary>
	/// whether current tetramino lies on the bottom screen side or 
	/// 
	/// (if it true so that`s time to join active figure to field blocks)
	/// </summary>
	bool isActiveFigureOnBottomOrFieldBlocks();

	/// <summary>
	/// checks block collision
	/// </summary>
	/// <param name="first"> first block coordinates </param>
	/// <param name="second"> second block coordinates </param>
	/// <returns> if one block collided another </returns>
	bool areBlocksCollided(const sf::Vector2f &first, const sf::Vector2f& second) const;



	/// <summary>
	/// creates a new figure
	/// (but the blocks will be deleted,
	///  you should firstly join it to field blocks by calling joinActiveToFieldBlocks
	///  if you want to leave old figure blocks on the screen while creating a new one)
	/// </summary>
	void resetActiveFigure();

	float getActiveFigureX();
};

