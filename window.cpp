#include "window.hh"
#include "PieceShape.hh"

window::window(PieceShape p)
{
    p.getCellSize();
    p.getHeight();
    p.getRect();
    p.getVect();
    p.getWidth();
}

window::~window()
{
}

sf::RenderWindow &window::getWin()
{
    return _win;
}
