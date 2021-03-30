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
void WindowManager::launchMusic(std::string music_path)
{
    if (!_music.openFromFile(music_path))
    {
        throw 1;
    }
    return _music.play();
}

void WindowManager::stopMusic()
{
    return _music.stop();
}

void WindowManager::pauseMusic()
{
    return _music.pause();
}

void WindowManager::relaunchMusic()
{
    return _music.play();
}

bool WindowManager::getIsMenu(){
    return _isMenu;
}