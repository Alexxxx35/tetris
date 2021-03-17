#ifndef DEF_WINDOW
#define DEF_WINDOW
#include <SFML/Graphics.hpp>

class window
{
private:
    int _cell_size = 25;
    int width = 10;
    int height = 20;
    sf::RenderWindow _win;
public:
    window(/* args */);
    sf::RenderWindow getWin();
    int getCell_size();
    int getWidth();
    int getHeight();
    void setCell_size();
    void setWidth();
    void setHeight();
    ~window();
};


#endif