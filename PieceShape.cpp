#include "PieceShape.hh"

PieceShape::PieceShape() {}
PieceShape::~PieceShape() {}

int PieceShape::GetPieceCellSize()
{
    return _cell_size;
}
void PieceShape::SetPieceCellSize(int NewCellSize)
{
    _cell_size = NewCellSize;
}

int PieceShape::GetWidth()
{
    return _width;
}
void PieceShape::SetWidth(int NewWidth)
{
    _width = NewWidth;
}
int PieceShape::GetHeight()
{
    return _height;
}
void PieceShape::SetHeight(int NewHeight)
{
    _height = NewHeight;
}
PieceShape::PieceShape()
{
}

PieceShape::~PieceShape()
{
}
