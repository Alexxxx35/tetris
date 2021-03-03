#include "WindowManager.hh"
#include "PieceShape.hh"

int main()
{
    // create the window
    //sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    PieceShape *p = new PieceShape();
    WindowManager *w = new WindowManager(*p);
    w->GetWindow().create(sf::VideoMode(p->GetWidth() * p->GetPieceCellSize(), p->GetHeight() * p->GetPieceCellSize()), "TETRIS");
    p->SetVector(p->GetPieceCellSize(), p->GetPieceCellSize());
    p->SetShape(p->GetPieceCellSize(), p->GetPieceCellSize());
    p->ChangeShapeColor(sf::Color::Red);

    // run the program as long as the window is open

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

        // end the current frame
        w->GetWindow().draw(p->GetShape());
        w->GetWindow().display();
    }

    return 0;
}