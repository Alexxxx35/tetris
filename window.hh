#ifndef DEF_WINDOW
#define DEF_WINDOW
#include <SFML/Graphics.hpp>
#include "PieceShape.hh"

class window
{
private:
    sf::RenderWindow _win;
public:
    window(PieceShape *p);
    sf::RenderWindow& getWin();
    ~window();
};

#endif