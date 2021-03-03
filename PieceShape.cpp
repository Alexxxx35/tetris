#include "PieceShape.hh"

PieceShape::PieceShape() {}
PieceShape::~PieceShape() {}

 void PieceShape::ChangeShapeColor(sf::Color NewColor){
     return _shape.setFillColor(NewColor);
 }

sf::Color PieceShape::GetColor()
{
    return _color;
}

void PieceShape::SetColor(sf::Color NewColor)
{
    _color = NewColor;
}

float PieceShape::GetPieceCellSize()
{
    return _cell_size;
}
void PieceShape::SetPieceCellSize(float NewCellSize)
{
    _cell_size = NewCellSize;
}

float PieceShape::GetWidth()
{
    return _width;
}
void PieceShape::SetWidth(float NewWidth)
{
    _width = NewWidth;
}
float PieceShape::GetHeight()
{
    return _height;
}
void PieceShape::SetHeight(float NewHeight)
{
    _height = NewHeight;
}

sf::RectangleShape PieceShape::GetShape()
{
    return _shape;
}

void PieceShape::SetShape(float x, float y)
{
    _shape.setSize(sf::Vector2f(x, y));
}

sf::Vector2f PieceShape::GetVector()
{
    return _vector;
}

void PieceShape::SetVector(float x, float y)
{
    _vector = sf::Vector2f(x, y);
}
