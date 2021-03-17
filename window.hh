#ifndef DEF_WINDOW
#define DEF_WINDOW
#include <SFML/Graphics.hpp>

class window
{
private:
    sf::RenderWindow _win;

public:
    window(/* args */);
    sf::RenderWindow getWin();
    ~window();
};

#endif