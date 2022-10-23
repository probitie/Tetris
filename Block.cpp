#include "Block.h"



Block::Block(const FigureColor& color, const sf::Vector2f& position) :
	color{ color }
{
	coordinates[0] = position.x;
	coordinates[1] = position.y;
};

