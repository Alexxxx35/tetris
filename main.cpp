#include "WindowManager.hh"
#include "PieceShape.hh"
#include "Menu.hh"
#include <iostream>
int main()
{
    // create the window
    //sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    PieceShape *p = new PieceShape();
    WindowManager *menuWindow = new WindowManager();
    WindowManager *w = new WindowManager(*p);

    w->GetWindow().create(sf::VideoMode(p->GetWidth() * p->GetPieceCellSize(), p->GetHeight() * p->GetPieceCellSize()), "TETRIS");
    menuWindow->GetWindow().create(sf::VideoMode(600, 480), "MENU");
    Menu *m = new Menu(menuWindow->GetWindow());

    p->SetX(p->GetWidth() * p->GetPieceCellSize() / 2);
    p->SetY(0);

    while (menuWindow->GetWindow().isOpen())
    {

        sf::Event event;
        while (menuWindow->GetWindow().pollEvent(event))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                m->MoveUp();
                break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                m->MoveDown();
                break;
            }

            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                menuWindow->GetWindow().close();
            }
            menuWindow->GetWindow().clear();
            m->draw(menuWindow->GetWindow());
            menuWindow->GetWindow().display();
        }
    }
    while (w->GetWindow().isOpen())
    {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (w->GetWindow().pollEvent(event))
        {

            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                w->GetWindow().close();
            }
        }

        // clear the window with black color
        w->GetWindow().clear();

        // draw everything here...
        p->DefineShape();
        //w->GetWindow().draw(m->getText());
        w->GetWindow().draw(p->GetShape());
        w->GetWindow().display();
    }

    return 0;
}