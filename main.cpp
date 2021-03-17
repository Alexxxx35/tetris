#include "WindowManager.hh"
#include "PieceShape.hh"

int main()
{
    // create the window
    //sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    PieceShape *p = new PieceShape();
    WindowManager *w = new WindowManager(*p);
    w->GetWindow().create(sf::VideoMode(p->GetWidth() * p->GetPieceCellSize(), p->GetHeight() * p->GetPieceCellSize()), "TETRIS");
    //p->SetSize(p->GetPieceCellSize(), p->GetPieceCellSize());
    p->SetX(p->GetWidth() * p->GetPieceCellSize() / 2);
    p->SetY(0);
    // p->SetVector(p->GetX(), p->GetY());
    // p->ColoredShape().setPosition(p->GetVector());
    // run the program as long as the window is open
    p->DefineShape();

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
        // p->DefineShape();
        w->GetWindow().draw(p->GetShape());
        w->GetWindow().display();
    }

    return 0;
}