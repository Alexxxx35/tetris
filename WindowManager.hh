#ifndef DEF_WINDOWMANAGER
#define DEF_WINDOWMANAGER

#include "PieceShape.hh"
#include "Menu.hh"
class WindowManager
{
public:
    ~WindowManager();
    WindowManager();
    WindowManager(PieceShape p);
    sf::RenderWindow& GetWindow();

private:
    sf::RenderWindow _window;

};
#endif
