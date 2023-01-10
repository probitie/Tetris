#pragma once
#include "GameField.h"
#include "libs.h"
#include "constants.h"
#include "logger.h"

using namespace sf;

class Tetris
{
private:
	GameField field;
	RenderWindow& window;

	bool lose = false;
	int score = 0;

	std::string font_filepath = "C:\\Projects\\cpp\\Tetris\\resources\\sansation.ttf";
	sf::Font font;

public:

	Tetris(RenderWindow& window);

	// start main loop
	void play();

private:

	// move to left/right/rotate
	void handleKeyEvent(const Event &ev);

	// move all figures down, delete rows if it necessary
	void update();

	// check if game can be continued or it is the end
	bool isGameFinish();

	// puts label on the window center "You lose\n(click to continue)"
	void outputUserLose();

	// delay between frames
	void pause();
};

