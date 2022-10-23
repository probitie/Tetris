#pragma once
#include "libs.h"
#include <SFML/Graphics/Sprite.hpp>
#include "figure_properties.h"


// todo maybe make it to inherit from sf::Sprite
class Block
{
private:
	float coordinates[2]; // x, y
	FigureColor color;

public:
	Block(const FigureColor& color, const sf::Vector2f &position);

};
