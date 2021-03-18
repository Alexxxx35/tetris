#include "window.hh"
#include "PieceShape.hh"
#include <iostream>
int main()
{
    PieceShape *p = new PieceShape();
    p->setVect(sf::Vector2f(p->getCellSize(), p->getCellSize()));
    p->getRect().setSize(sf::Vector2f(p->getVect()));
    p->getRect().setPosition(0, 0);
    p->getRect().setFillColor(sf::Color::Red);
    window *win = new window(p);

    //sf::RectangleShape cell(sf::Vector2f(50.0, 50.0));
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
        win->getWin().draw(p->getRect());
        //win->getWin().draw(cell);
        win->getWin().display();
    }
    return 0;
}