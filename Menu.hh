#ifndef DEF_MENU
#define DEF_MENU
#include "SFML/Graphics.hpp"
#include "WindowManager.hh"
class Menu
{
private:
    int selectedItem;
    sf::Font font;
    sf::Text _text[3];
    unsigned int _width;  //normally take value of window
    unsigned int _height; //normally take value of window
    int const numberOfItems = 3;
    int selectedItemIndex;

public:
    int getSelectedItemIndex();
    void draw(sf::RenderWindow &window);
    sf::Text *getText();
    void MoveUp();
    void MoveDown();
    Menu(sf::RenderWindow &window);
    ~Menu();
};

#endif