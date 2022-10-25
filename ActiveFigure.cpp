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

ActiveFigure::ActiveFigure(sf::RenderWindow& window) : window{window}
{
    debuglog("init active figure container in this window");
	setColor(FigureColor::darkBlue);
}

void ActiveFigure::newRandowFigure()
{
    debuglog("create new figure");
	setProperties(FigureForm::T, FigureColor::darkBlue, sf::Vector2f(0.0f, 0.0f));
}

void ActiveFigure::draw()
{
	// if game field cell has value 0 - there is no brick
	// BRICKS::darkBlue - first brick color
	// BRICKS::violet - second brick color etc

	// TODO go through game field matrix and paint necessary block in
	// a real window

	// TODO move to method std::array<Point, 4> createFigure(TETRAMINO::J)

	// TODO draw all tetramino figures in other method


	// draw it on the game field
	for (int i{0}; i < 4; ++i)
	{
		// use only one poor(( sprite
		// to draw our figure

		Block drawBlock(currentColor, toAbsoluteCoordinates(relativeCoordinates[i]));
		drawBlock.draw(window);
	}

}
void ActiveFigure::setColor(FigureColor color)
{
	currentColor = color;
}

void ActiveFigure::setProperties(const FigureForm& form, const FigureColor& color, const sf::Vector2f& position)
{
    debuglog("set new properties to the active figure conainer");

	coordinates = position;

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

// only changes figure coordinates but not the bricks
void ActiveFigure::move(const sf::Vector2f& vector)
{
	this->coordinates.x += vector.x;
	this->coordinates.y += vector.y;
}

// only changes figure coordinates but not the bricks
void ActiveFigure::setLocation(const sf::Vector2f& vector)
{
	this->coordinates.x = vector.x;
	this->coordinates.y = vector.y;
}

void ActiveFigure::rotate()
{
    debuglog("rotate figure");

	// second block is a rotate center ( index 1 )
	const Point& rotateCenter = relativeCoordinates[1];

	for (auto& blockPoint : relativeCoordinates)
	{
		int dx = blockPoint.y - rotateCenter.y;
		int dy = blockPoint.x - rotateCenter.x;

		blockPoint.x = rotateCenter.x - dx;
		blockPoint.y = rotateCenter.y + dy;

	}


}

const double ActiveFigure::getMostLeftX() const
{
	// TODO stl min
	double mostLeftX{ toAbsoluteCoordinates(relativeCoordinates.at(0)).x };
	for (auto& el : relativeCoordinates)
	{
		auto absCoord = toAbsoluteCoordinates(el);
		if (absCoord.x < mostLeftX)
		{
			mostLeftX = absCoord.x;
		}
	}
	return mostLeftX;
}

const double ActiveFigure::getMostRightX() const
{
	// TODO stl max
	double mostRightX{ toAbsoluteCoordinates(relativeCoordinates.at(0)).x };
	for (auto& el : relativeCoordinates)
	{
		auto absCoord = toAbsoluteCoordinates(el);
		if (absCoord.x > mostRightX)
		{
			mostRightX = absCoord.x;
		}
	}
	return mostRightX + TETRIS_BLOCK_W;
}

const double ActiveFigure::getBottomY() const
{
	// TODO stl max
	double bottomY{ toAbsoluteCoordinates(relativeCoordinates.at(0)).y };
	for (auto& el : relativeCoordinates)
	{
		auto absCoord = toAbsoluteCoordinates(el);
		if (absCoord.y > bottomY)
		{
			bottomY = absCoord.y;
		}
	}
	return bottomY + TETRIS_BLOCK_H;
};

const std::vector<sf::Vector2f> ActiveFigure::getAllBlocksCoordinates() const
{
    std::vector<sf::Vector2f> result;
	for (const auto& el : relativeCoordinates)
	{
		result.push_back(toAbsoluteCoordinates(el));
	}
	return result;
}

const std::vector<Block> ActiveFigure::getBlocks()
{
	debuglog("giving figure blocks");
	std::vector<Block> res{};
	for (auto &el : relativeCoordinates)
		res.push_back(Block(currentColor, toAbsoluteCoordinates(el)));
    return res;
}
