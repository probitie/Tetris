#include "ActiveFigure.h"


// available figures
array2D(7, TETRIS_FIGURE_BLOCK_AMOUNT_COL) figures // amount of available figures forms / figure height
{
    1, 3, 5, 7, // I
        2, 4, 5, 7, // S
        3, 5, 4, 6, // Z
        3, 5, 4, 7, // T
        2, 3, 5, 7, // L
        3, 5, 7, 6, // J
        2, 3, 4, 5, // O
};



sf::Vector2f ActiveFigure::toAbsoluteCoordinates(const Point& relative) const
{
    double x = coordinates.x + relative.x * TETRIS_BLOCK_W;
    double y = coordinates.y + relative.y * TETRIS_BLOCK_H;
    return sf::Vector2f(x, y); // TODO maybe replace with "return {x, y};"
}

ActiveFigure::ActiveFigure(sf::RenderWindow& window)
{
    debuglog("init active figure container in this window");
}

void ActiveFigure::newRandowFigure()
{
    debuglog("create new figure");

}

void ActiveFigure::setProperties(const FigureForm& form, const FigureColor& color, const sf::Vector2f& position)
{
    debuglog("set new properties to the active figure conainer");

	// create figure
	for (int i{ 0 }; i < TETRIS_FIGURE_BLOCK_AMOUNT_COL; ++i)
	{
		// draw only those bricks that exist in figures array
		// ( other will be set as 0 )

		// TODO 2 is amount columns in game figure
		// example:
		//		0 0
		//		1 0
		//		1 1
		//		0 1
		//
		//  This is an "S" figure in a tetris game
		//
		//	so we have there only 2 columns and 4 rows, block index
		//	is varying from 0 to 7
		//
		//  and to get X coordinate - we need to calculate block_number(which is 0-7) % 2
		//  for 5 we will get 2 - row index
		//  and 5/2 - will get 1 - column index
		relativeCoordinates[i].x = figures[static_cast<int>(form)][i] % TETRIS_FIGURE_BLOCK_AMOUNT_ROW;
		relativeCoordinates[i].y = figures[static_cast<int>(form)][i] / TETRIS_FIGURE_BLOCK_AMOUNT_ROW;

	}
	// load texture
	//const std::string& BRICKS_TEXTURE_PATH = "C:\\Projects\\cpp\\Tetris\\images\\bricks.PNG";
	// // full brick texture (actually there are 7 bricks)
	// Texture brickTextureImage;
	//brickTextureImage.loadFromFile(BRICKS_TEXTURE_PATH);

	// default color
	// 
	//setColor(TETRAMINO_COLORS::darkBlue);

	// set up figure blocks
	//createFigure();
}

void ActiveFigure::move(const sf::Vector2f& vector)
{
    debuglog("moving to x: " << vector.x << "; y: " << vector.y << ";");
    //rectangle.move(vector);

}

void ActiveFigure::rotate()
{
    debuglog("rotate figure");
}

const double ActiveFigure::getMostLeftX() const
{
    return 0;
}

const double ActiveFigure::getMostRightX() const
{
    return 0;
}

const std::vector<sf::Vector2f> ActiveFigure::getEachBottomLineCoordinates() const
{
    return std::vector<sf::Vector2f>();
}

const std::vector<std::unique_ptr<Block>> ActiveFigure::popBottomBlocks()
{
    return std::vector<std::unique_ptr<Block>>();
}
