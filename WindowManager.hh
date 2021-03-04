#ifndef DEF_WINDOWMANAGER
#define DEF_WINDOWMANAGER

#include "PieceShape.hh"
class WindowManager
{
public:
    ~WindowManager();
    WindowManager(PieceShape p);
    sf::RenderWindow& GetWindow();

private:
    sf::RenderWindow _window;

};
#endif
