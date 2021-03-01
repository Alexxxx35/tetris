#include "WindowManager.cpp"

int main()
{
    // create the window
    //sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    PieceShape *p=new PieceShape();
    WindowManager *w = new WindowManager(*p);
   
    // run the program as long as the window is open
    while (w.GetWindow()->isOpen())
    {

        // sf::RectangleShape rectangle(sf::Vector2f(30, 60));
        // rectangle.setSize(sf::Vector2f(200, 400));
        // rectangle.setPosition(sf::Vector2f(300, 100));
        // rectangle.setFillColor(sf::Color::Black);
        // rectangle.setOutlineThickness(2.0);
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (windowManager.GetWindow()->pollEvent(event))
        {
            windowManager.GetWindow()->clear();

            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                windowManager.GetWindow()->close();
            }
        }

        // clear the window with black color
        windowManager.GetWindow()->clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        // end the current frame
        //window.draw(rectangle);
        windowManager.GetWindow()->display();
    }

    return 0;
}