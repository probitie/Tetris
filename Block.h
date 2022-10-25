#pragma once
#include "libs.h"
#include "constants.h"
#include "figure_properties.h"


// todo maybe make it to inherit from sf::Sprite
class Block
{
private:
	sf::Vector2f coordinates; // x, y
	FigureColor color;

public:
	Block(const FigureColor& color, const sf::Vector2f position);

	inline sf::Vector2f getPosition() const { return coordinates; }

	void draw(sf::RenderWindow& window);
};
