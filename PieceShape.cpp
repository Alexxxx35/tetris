#include "PieceShape.hh"

PieceShape::PieceShape()
{
}

PieceShape::~PieceShape()
{
}

float PieceShape::getCellSize()
{
    return _cell_size;
}
float PieceShape::getWidth()
{
    return _width;
}
float PieceShape::getHeight()
{
    return _height;
}
void PieceShape::setCellSize(float newValue)
{
    _cell_size = newValue;
}
void PieceShape::setWidth(float newValue)
{
    _width = newValue;
}
void PieceShape::setHeight(float newValue)
{
    _height = newValue;
}
sf::RectangleShape PieceShape::getRect()
{
    return _rect;
}
sf::Vector2f PieceShape::getVect()
{
    return _vect;
}
void PieceShape::setVect(sf::Vector2f newVect)
{
    _vect = newVect;
}