#pragma once
#include "libs.h"
#include "Tetramino.h"

namespace tetrisGame
{





	class TetrisGame;
}


class tetrisGame::TetrisGame
{
public:

	/**
	 Default constructor that initializes window, event listeners, other values
	*/
	TetrisGame();

	/**
	starts the game loop
	*/
	void run();


private:

	const std::unique_ptr<RenderWindow> __window_ptr;
	RenderWindow& window;

	// the game field - 2d array
	array2D(GAMEFIELD_ROWS, GAMEFIELD_COLS) gameField { 0 };



	/**
	* when user presses left/right arrow
	*	 - move actife figure to the left/right
	*		respectively
	*/
	void handleHorizontalMovement(const Event& event, Tetramino& activeTetramino);

	/**
	* 
	*/
	void handleRotate(const Event& event, Tetramino& activeTetramino);

	/**
	* 
	*/
	void moveDown(Tetramino &activeTetramino,const int delay_ms = 300);
};

