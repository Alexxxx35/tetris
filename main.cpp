#include "window.hh"
#include "PieceShape.hh"
int main()
{
    window *win = new window;
    PieceShape *p = new PieceShape;
    win->getWin().create(sf::VideoMode(p->getWidth() * p->getCellSize(),
                                       p->getHeight() * p->getCellSize()),
                         "Tetris");
    while (win->getWin().isOpen())
    {
        sf::Event e;
        while (win->getWin().pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                win->getWin().close();
            }
        }
        win->getWin().clear();
        win->getWin().display();
    }
    return 0;
}