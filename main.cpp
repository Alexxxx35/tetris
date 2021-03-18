#include "window.hh"
#include "PieceShape.hh"
#include <iostream>
int main()
{
    PieceShape *p = new PieceShape();
    p->setVect(sf::Vector2f(p->getCellSize(), p->getCellSize()));
    //std::cout << p->getVect().x << std::endl;
    p->setRect(p->getRect()).setSize(sf::Vector2f(p->getVect()));
    std::cout << p->getRect().getSize().x << std::endl;
    p->getRect().setPosition(30, 30);
    p->getRect().setFillColor(sf::Color::Red);
    window *win = new window(*p);
    win->getWin().create(sf::VideoMode(p->getWidth() * p->getCellSize(),
                                       p->getHeight() * p->getCellSize()),
                         "Tetris");
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
        sf::RectangleShape cell2 = p->getRect();
        win->getWin().draw(cell2);
        //win->getWin().draw(cell);
        win->getWin().display();
    }
    return 0;
}