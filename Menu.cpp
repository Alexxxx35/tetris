#include "Menu.hh"
#include "WindowManager.hh"
#include "iostream"
Menu::Menu(sf::RenderWindow &window)
{
    if (!_font.loadFromFile("arial.ttf"))
    {
        throw 1;
    }
    if (!_texture.loadFromFile("src/tetris_background.jpg"))
    {
        throw 1;
    }
    if (!_titleFont.loadFromFile("disko.ttf"))
    {
        throw 1;
    }

    _width = window.getSize().x;  // => adapter la sprite a la taille de la fenetre
    _height = window.getSize().y; // => adapter la sprite a la taille de la fenetre
    _font.loadFromFile("arial.ttf");
    _sprite.setTexture(_texture);
    _sprite.setScale(_width / _sprite.getLocalBounds().width,
                     _height / _sprite.getLocalBounds().height);
    for (int i = 0; i < numberOfItems; i++)
    {
        if (i == 0)
        {
            _text[i].setString("TETRIS");
            _text[i].setFont(_titleFont);
            _text[i].setFillColor(sf::Color::Red);
            _text[i].setCharacterSize(48);
            _text[i].setPosition(sf::Vector2f(_width / 2.4, (i * _height / numberOfItems)));
        }
        if (i == 1)
        {
            _text[i].setString("Start");
        }
        if (i == 2)
        {
            _text[i].setString("Option");
        }
        if (i == 3)
        {
            _text[i].setString("Exit");
        }
        if (i > 0)
        {
            _text[i].setFont(_titleFont);
            _text[i].setFillColor(sf::Color::White);
            _text[i].setCharacterSize(32);
            _text[i].setPosition(sf::Vector2f(_width / 2.2, (i * _height / numberOfItems)));
        }
        //std::cout << (i * _height / numberOfItems) << std::endl;
    }
}
Menu::~Menu()
{
}
int Menu::getSelectedItemIndex()
{
    return selectedItemIndex;
}

void Menu::draw(sf::RenderWindow &window)
{
    window.draw(_sprite);
    for (int i = 0; i < numberOfItems; i++)
    {

        window.draw(_text[i]);
    }
}

sf::Vector2f Menu::getTextPosition(int i)
{
    return _text[i].getPosition();
}

void Menu::MoveUp()
{

    if (selectedItemIndex > 1)
    {
        _text[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        _text[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{

    if (selectedItemIndex < numberOfItems - 1)
    {
        _text[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        _text[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::underlignText(int i)
{
    return _text[i].setStyle(sf::Text::Underlined);
}

void Menu::unUnderlignText(int i)
{
    return _text[i].setStyle(sf::Text::Regular);
}

// sf::Texture Menu::getTexture()
// {
//     return _texture;
// }

sf::Sprite Menu::getSprite()
{
    return _sprite;
}

// sf::Music Menu::getMusic(){
//     return _music;
// }

void Menu::launchMusic(std::string music_path)
{
    if (!_music.openFromFile(music_path))
    {
        throw 1;
    }
    return _music.play();
}

void Menu::relaunchMusic()
{
    return _music.play();
}

void Menu::stopMusic()
{
    return _music.stop();
}

void Menu::pauseMusic()
{
    return _music.pause();
}
