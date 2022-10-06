#include "ActiveFigure.h"


ActiveFigure::ActiveFigure(sf::RenderWindow& window)
{
    debuglog("init active figure container in this window");
}

void ActiveFigure::newRandowFigure()
{
    debuglog("create new figure");

    // TODO THAT'S JUST FOR DEVELOPING NOT FOR ACTUAL USE
    rectangle.setSize(sf::Vector2f(21, 21));
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setOutlineThickness(5);
}

void ActiveFigure::setProperties(const FigureForm& form, const FigureColor& color, const sf::Vector2f& position)
{
    debuglog("set new properties to the active figure conainer");
}

void ActiveFigure::move(const sf::Vector2f& vector)
{
    debuglog("moving to x: " << vector.x << "; y: " << vector.y << ";");
    rectangle.move(vector);

}

void ActiveFigure::rotate()
{
    debuglog("rotate figure");
}

const double ActiveFigure::getMostLeftX() const
{
    return 0.0;
}

const double ActiveFigure::getMostRightX() const
{
    return 0.0;
}

const std::vector<sf::Vector2f> ActiveFigure::getEachBottomLineCoordinates() const
{
    return std::vector<sf::Vector2f>();
}

const std::vector<std::unique_ptr<Block>> ActiveFigure::popBottomBlocks()
{
    return std::vector<std::unique_ptr<Block>>();
}
