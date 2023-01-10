#include "Tetris.h"
#include <SFML/System/Sleep.hpp>
#include <sstream>

Tetris::Tetris(RenderWindow& window)
	: window{ window }, field{ window }
{
	sf::Font font;
	if (!font.loadFromFile(font_filepath))
	{
		throw std::exception("can not load font");
	}
}

void Tetris::play()

{
	Event ev;

	while (window.isOpen())
	{
		// check end of the game
		if (isGameFinish())
		{
			// for now end of the game means that user lose
			outputUserLose();

			// todo wait for user click before closing the application
			std::cin.get();
			return;
		}

		// handle user events
		while (window.pollEvent(ev))
		{
			if (ev.type == Event::Closed)
				window.close();

			if (ev.type == Event::KeyPressed)
				handleKeyEvent(ev);
		}


		// background color
		window.clear(TETRIS_BACKGROUND_COLOR);

		update();

		field.draw();
		window.display();

		pause();
	}
}

void Tetris::handleKeyEvent(const Event &ev)
{
	// events are - move active tetramino left - move right - move down
	if (ev.key.code == TETRIS_RIGHT) // TODO event getKey == TETRIS_KEY_LEFT
	{
		debuglog("moving right");
		field.moveActiveFigureRight();
	}
	else if (ev.key.code == TETRIS_LEFT)
	{
		debuglog("moving left");
		field.moveActiveFigureLeft();
	}
	else if (ev.key.code == TETRIS_ROTATE)
	{
		field.rotateActiveFigure();
	}
	else if (ev.key.code == TETRIS_FORCE_DOWN)
	{
		field.moveActiveFigureForceDown();
	}
	else
	{
		debuglog("unknown key pressed");
	}
}

void Tetris::update()
{
	// if tetramino is already fallen on the field bottom/blocks
	if (field.isActiveFigureOnBottomOrFieldBlocks())
	{
		
		if (field.getActiveFigureX() < 0)
			lose = true;
		field.resetActiveFigure();

	}
	else
	{
		//score++;
		// check if it is time to squeeze blocks on the field
		// but before compressing we need to find full rows
		// (wihout spaces in them), then delete all blocks in them
		// after that we can squeeze blocks
		for (auto& row : field.getFullRowsIndexes())
		{
			field.deleteRowAndSqueeze(row);
			score+=1;
		}

		// move tetramino on a step down
		field.moveActiveFigureDown();
	}
}

bool Tetris::isGameFinish()
{
	// asks game field if activeFigure has spawned or not 
	// ( if it is unable t spawn it means there is no space left )
	return lose;
}

void Tetris::outputUserLose()
{
	debuglog("saying to user he lose the game");
	std::cout << "Your score was " << score << "00\n";
}

void Tetris::pause()
{
	//sleep(sf::milliseconds(TETRIS_FRAMES_DELAY_MS));
}

