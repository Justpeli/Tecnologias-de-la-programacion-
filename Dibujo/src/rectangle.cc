#include "rectangle.hh"

rectangle::rectangle(int width, int height, int x, int y, sf::Color color)
{
    rectangleshape= new sf::RectangleShape(sf::Vector2f(width, height));
    rectangleshape->setPosition(sf::Vector2f(x,y));
    rectangleshape->setFillColor(color);
}

rectangle::~rectangle()
{
}

sf::RectangleShape* rectangle::GetShape() const
{
    return rectangleshape;
}