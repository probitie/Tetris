#include "Block.h"


static std::unique_ptr<sf::Texture> loadTexture();
static void setSpriteColor(FigureColor color);

std::unique_ptr<sf::Texture> texture = loadTexture();
sf::Sprite brick{};

static std::unique_ptr<sf::Texture> loadTexture()
{
	texture = std::make_unique<sf::Texture>();
	texture->loadFromFile(TEXTURE_PATH);
	return std::move(texture);
}

static void setSpriteColor(FigureColor color)
{
	brick.setTexture(*texture);
	brick.setTextureRect(sf::IntRect(2+21, 2, 21, 21));
}

Block::Block(const FigureColor& color, const sf::Vector2f position) :
	color{ color }
{
	coordinates = position;
};

void Block::draw(sf::RenderWindow& window)
{
	setSpriteColor(color);
	brick.setPosition(coordinates);
	window.draw(brick);
}

