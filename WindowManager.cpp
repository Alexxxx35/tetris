#include "WindowManager.hh"

WindowManager::WindowManager() {}

WindowManager::WindowManager(PieceShape p)
{
    //_window.create(sf::VideoMode(p.GetWidth() * p.GetPieceCellSize(), p.GetHeight() * p.GetPieceCellSize()), "TETRIS");
    //_window.setFramerateLimit(60);
    p.GetHeight();
}

WindowManager::~WindowManager() {}

sf::RenderWindow &WindowManager::GetWindow()
{
    return _window;
}

bool WindowManager::getPause()
{
    return _pause;
}

void WindowManager::inversePause()
{
    _pause = !_pause;
}