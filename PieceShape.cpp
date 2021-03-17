#include "PieceShape.hh"

PieceShape::PieceShape(/* args */)
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