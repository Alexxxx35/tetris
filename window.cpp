#include "window.hh"
#include "PieceShape.hh"

window::window(PieceShape p)
{
    p.getRect();
}

window::~window()
{
}

sf::RenderWindow &window::getWin()
{
    return _win;
}
