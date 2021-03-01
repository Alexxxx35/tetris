#include "WindowManager.hh"

WindowManager::WindowManager(PieceShape p)
{
    _window.create(sf::VideoMode(p.GetWidth() * p.GetPieceCellSize(), p.GetHeight() * p.GetPieceCellSize()), "TETRIS");
    _window.setFramerateLimit(60);

}

WindowManager::~WindowManager() {}

sf::RenderWindow& WindowManager::GetWindow(){
    return _window;
}