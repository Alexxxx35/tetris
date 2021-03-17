#include "window.hh"
#include "PieceShape.hh"
int main()
{
    PieceShape *p = new PieceShape();
    window *win = new window(*p);

    win->getWin().create(sf::VideoMode(p->getWidth() * p->getCellSize(),
                                       p->getHeight() * p->getCellSize()),
                         "Tetris");
    p->setVect(sf::Vector2f(p->getCellSize(), p->getCellSize()));
    p->getRect().setSize(sf::Vector2f(p->getVect()));
    
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
        p->getRect().setFillColor(sf::Color::Green);
        win->getWin().draw(p->getRect());
        win->getWin().display();
    }
    return 0;
}