#pragma once
#include "libs.h"

class TetrisGame
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
	const std::string& TEXTURE_PATH = "C:\\Projects\\cpp\\Tetris\\images\\bricks.PNG";

	const std::unique_ptr<RenderWindow> __window_ptr;
	RenderWindow& window;

	// sprites on canvas that draw each frame update
	//  TODO maybe call it "canvas"
	std::vector<Sprite> sprites;


	/** 
	draws all sprites with their position on the window
	
	each added sprite must be stored in spites field 
	*/
	void drawAllSprites();

	/**
	creates a simple sprite and adds it to the window
	*/
	void createSprite(const Texture& texture);

	Texture&& createTexture();
};

