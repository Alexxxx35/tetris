#include "window.hh"
#include "PieceShape.hh"

window::window(PieceShape *p)
{
    _win.create(sf::VideoMode(p->getWidth() * p->getCellSize(),
                                       p->getHeight() * p->getCellSize()),
                         "Tetris");
}

window::~window()
{
}

sf::RenderWindow &window::getWin()
{
    return _win;
}
