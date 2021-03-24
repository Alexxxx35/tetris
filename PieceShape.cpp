#include "PieceShape.hh"
#include <iostream>
PieceShape::PieceShape() {}
PieceShape::~PieceShape() {}

void PieceShape::ChangeShapeColor(sf::Color NewColor)
{
    return _size.setFillColor(NewColor);
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

sf::RectangleShape PieceShape::GetSize()
{
    return _size;
}

void PieceShape::SetSize(float x, float y)
{
    _size.setSize(sf::Vector2f(x, y));
}

sf::Vector2f PieceShape::GetVector()
{
    return _vector;
}

void PieceShape::SetVector(float x, float y)
{
    _vector = sf::Vector2f(x, y);
}

void PieceShape::DefineShape()
{
    _Shape.setSize(sf::Vector2f(_width, _height));
    // Get the system time.
    //unsigned seed = time(0);

    // Seed the random number generator.
    //srand(seed);
    int r = rand() % 7;
    //std::cout << "random value: " << r << std::endl;
    _Shape.setFillColor(_listOfColors[r]);
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (_patterns[r][y][x])
            {
                _Shape.setPosition(sf::Vector2f(_X+x*_cell_size,_Y+y*_cell_size));
            }
        }
    }
}

double PieceShape::GetX()
{
    return _X;
}

void PieceShape::SetX(double NewX)
{
    _X = NewX;
}

double PieceShape::GetY()
{
    return _Y;
}

void PieceShape::SetY(double NewY)
{
    _Y = NewY;
}

sf::RectangleShape PieceShape::GetShape()
{
    return _Shape;
}