#pragma once
#include<SFML/Graphics.hpp>

class rectangle
{
private:
sf::RectangleShape* rectangleshape{};
public:
    rectangle(int width, int height, int x, int y, sf::Color color);
    ~rectangle();
    sf::RectangleShape* GetShape() const;

};