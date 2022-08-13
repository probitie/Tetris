#include "TetrisGame.h"

TetrisGame::TetrisGame()
	: __window_ptr{ std::make_unique<RenderWindow>(VideoMode{QUALITY_480}, "Tetris") },
	window{*__window_ptr},
	sprites{}
{

}

void TetrisGame::drawAllSprites()
{
	std::for_each(sprites.begin(), sprites.end(), [this](const Sprite& elem) {window.draw(elem); });
}

Texture&& TetrisGame::createTexture()
{
	// create texture
	Texture texture;
	texture.loadFromFile(TEXTURE_PATH);
	return std::move(texture);
}

void TetrisGame::run()
{
	// TODO that method does not work properly
	//const Texture& texture = createTexture();
	Texture texture;
	texture.loadFromFile(TEXTURE_PATH);


	while (window.isOpen())
	{
		// handle user events
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}


		window.clear(Color::Green);
		createSprite(texture);

		window.display();
	}
}

/*

TODO остановился на том что нарисовал 1 кубик тетриса

*/

void TetrisGame::createSprite(const Texture& texture)
{
	Sprite sprite(texture);
	sprite.setTextureRect(IntRect(2, 2, 21, 21));
	window.draw(sprite);
}
