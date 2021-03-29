#include "WindowManager.hh"
#include "PieceShape.hh"
#include "Menu.hh"
#include <iostream>
int main()
{
    PieceShape *p = new PieceShape();
    WindowManager *menuWindow = new WindowManager();
    WindowManager *w = new WindowManager(*p);

    w->GetWindow().create(sf::VideoMode(p->GetWidth() * p->GetPieceCellSize(), p->GetHeight() * p->GetPieceCellSize()), "TETRIS");
    menuWindow->GetWindow().create(sf::VideoMode(600, 480), "MENU");
    Menu *m = new Menu(menuWindow->GetWindow());
    //m->launchMusic();

    p->SetX(p->GetWidth() * p->GetPieceCellSize() / 2);
    p->SetY(0);

    //MENU WINDOW
    m->launchMusic("src/tetris-game-boy-02-a-type.wav");

    while (menuWindow->GetWindow().isOpen())
    {

        //std::cout << m->getSelectedItemIndex() << std::endl;
        sf::Event event;
        while (menuWindow->GetWindow().pollEvent(event))
        {
            int x = sf::Mouse::getPosition(menuWindow->GetWindow()).x;
            int y = sf::Mouse::getPosition(menuWindow->GetWindow()).y;
            if (!menuWindow->getPause())
            {
                if (event.type == sf::Event::MouseWheelMoved)
                {
                    std::cout << "wheel movement: " << event.mouseWheel.delta << std::endl;
                    std::cout << "mouse x: " << event.mouseWheel.x << std::endl;
                    std::cout << "mouse y: " << event.mouseWheel.y << std::endl;
                }

                if (x >= 273 && x <= 356 && y >= 130 && y <= 154)
                {
                    m->underlignText(1);
                }
                else
                {
                    m->unUnderlignText(1);
                }

                if (event.type == sf::Event::KeyReleased)
                {
                    if (event.key.code == sf::Keyboard::Space)
                    {
                        m->pauseMusic();
                        menuWindow->inversePause();
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    m->MoveUp();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    m->MoveDown();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && m->getSelectedItemIndex() == 0)
                {
                    m->stopMusic();
                    menuWindow->GetWindow().close();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && m->getSelectedItemIndex() == 1)
                {
                    menuWindow->GetWindow().close();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && m->getSelectedItemIndex() == 2)
                {
                    menuWindow->GetWindow().close();
                }

                if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    menuWindow->GetWindow().close();
                }
                menuWindow->GetWindow().clear();
                //menuWindow->GetWindow().draw(m->getSprite());
                m->draw(menuWindow->GetWindow());
                menuWindow->GetWindow().display();
            }

            else if (menuWindow->getPause())
            {
                if (event.type == sf::Event::KeyReleased)
                {
                    if (event.key.code == sf::Keyboard::Space)
                    {
                        m->relaunchMusic();
                        menuWindow->inversePause();
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    m->MoveUp();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    m->MoveDown();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && m->getSelectedItemIndex() == 0)
                {
                    menuWindow->GetWindow().close();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && m->getSelectedItemIndex() == 1)
                {
                    menuWindow->GetWindow().close();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && m->getSelectedItemIndex() == 2)
                {
                    menuWindow->GetWindow().close();
                }

                if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    menuWindow->stopMusic();
                    menuWindow->GetWindow().close();
                }
            }
        }
    }
    m->stopMusic();
    //GAME WINDOW
    w->launchMusic("src/tetris-game-boy-03-b-type.wav");
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
        w->GetWindow().draw(p->GetShape());
        w->GetWindow().display();
    }

    return 0;
}