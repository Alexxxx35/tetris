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
    sf::RenderWindow &GetWindow();
    bool getPause();
    void inversePause();

private:
    bool _pause = false;
    sf::RenderWindow _window;
};
#endif
