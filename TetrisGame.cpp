#include "TetrisGame.h"

namespace tetrisGame
{
	// default constuctor (must be only one)
	TetrisGame::TetrisGame()
		: __window_ptr{ std::make_unique<RenderWindow>(VideoMode{APP_WIDTH, APP_HEIGHT}, "Tetris") },
		window{ *__window_ptr }
	{
	}




	void TetrisGame::run()
	{

		// which is fallen down now
		Tetramino activeTetramino{ TETRAMINO_FORMS::T, Vector2f{0.0f, 0.0f} };


		while (window.isOpen())
		{
			// handle user events
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();

				handleHorizontalMovement(event, activeTetramino);
				handleRotate(event, activeTetramino);
			}

			moveDown(activeTetramino);


			// set background color
			window.clear(Color::Green);
			
			// TODO just implement Drawable interface
			activeTetramino.drawIn(window);

			window.display();
		}
	}

	void TetrisGame::handleHorizontalMovement(const Event& event, Tetramino& activeTetramino)
	{
		// on how much blocks to move
		int dBlockX = 0;

		// only when key is pressed 
		// (otherwise it will work also when user releases the button
		//		-> we will get a doubleclick)

		// tetramino can not move outh the window
		if (event.type == Event::KeyPressed)
		{
			if (event.key.code == Keyboard::Left && activeTetramino.canMoveLeftThan(BRICK_SIZE / 2))
				dBlockX = -1;

			if (event.key.code == Keyboard::Right && activeTetramino.canMoveRightThan(GAMEFIELD_WIDTH - 3 * BRICK_SIZE / 2)) // 3*brick/2 -> 1.5 brick
				dBlockX = 1;
		}
		

		activeTetramino.move(dBlockX, 0);
	}

	void TetrisGame::handleRotate(const Event& event, Tetramino& activeTetramino)
	{
		// only when key is pressed 
		// (otherwise it will work also when user releases the button
		//		-> we will get a doubleclick)
		if (event.type == Event::KeyPressed)
		{
			if (event.key.code == Keyboard::Up)
				activeTetramino.rotate();
		}
	}

	void TetrisGame::moveDown(Tetramino &activeTetramino, const int delay)
	{
		// with static clock
		// each method call
		// check current clock with delay
		// if so
		// reset clock and move
		static Clock clock;
		int time = clock.getElapsedTime().asMilliseconds();

		if (time > delay)
		{
			activeTetramino.move(0, 1);
			clock.restart();
		}

	}

}