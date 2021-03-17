#include "PieceShape.hh"

PieceShape::PieceShape()
{
}

PieceShape::~PieceShape()
{
}

int PieceShape::getCellSize()
{
    return _cell_size;
}
int PieceShape::getWidth()
{
    return _width;
}
int PieceShape::getHeight()
{
    return _height;
}
void PieceShape::setCellSize(int newValue)
{
    _cell_size = newValue;
}
void PieceShape::setWidth(int newValue)
{
    _width = newValue;
}
void PieceShape::setHeight(int newValue)
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