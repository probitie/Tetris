#include "gmock/gmock.h"
#include "Tetris.h"
#include "gtest/gtest.h"
#include "libs.h"
#include "constants.h"
#include "logger.h"

/// <summary>
/// this is the entry point of the app
/// </summary>
int main()
{
//#define TETRIS_TESTING

	srand(time(NULL));

#ifdef TETRIS_TESTING
	testing::InitGoogleTest();
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
#else

	// here is an actual start of the game


	using namespace sf;

	/*
	// auto __window_ptr = std::make_unique<sf::RenderWindow>(sf::VideoMode{ tetris::APP_WIDTH, tetris::APP_HEIGHT }, "Tetris")
	
		window{ *__window_ptr }
		*/

	debuglog("starting the game");
	RenderWindow window{ sf::VideoMode{ TETRIS_APP_WIDTH, TETRIS_APP_HEIGHT }, "Tetris" };
	Tetris game { window };
	game.play(); // main loop is here ...
	window.close();

	return EXIT_SUCCESS;
#endif
}
