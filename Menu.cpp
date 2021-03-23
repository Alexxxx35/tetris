#include "Menu.hh"
#include "WindowManager.hh"
#include "iostream"
Menu::Menu(sf::RenderWindow &window)
{
    if (!_font.loadFromFile("arial.ttf"))
    {
        throw 1;
    }
    if (!_texture.loadFromFile("src/tetris.jpeg"))
    {
        throw 1;
    }
    _width = window.getSize().x;
    _height = window.getSize().y;
    _font.loadFromFile("arial.ttf");
    _texture.loadFromFile("src/tetris.jpeg", sf::IntRect(10, 10, 32, 32));
    _sprite.setTexture(_texture);
    _sprite.setColor(sf::Color::White);
    _sprite.setTextureRect(sf::IntRect(0, 0, 160, 30));
    _sprite.setPosition(100, 100);
    for (int i = 0; i < numberOfItems; i++)
    {
        if (i == 0)
        {
            _text[i].setString("TETRIS");
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
        _text[i].setFont(_font);
        _text[i].setFillColor(sf::Color::White);
        _text[i].setPosition(sf::Vector2f(_width / 2, (i * _height / numberOfItems)));
        std::cout << (i * _height / numberOfItems) << std::endl;
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

    for (int i = 0; i < numberOfItems; i++)
    {

        window.draw(_text[i]);
    }
    window.draw(_sprite);
}

sf::Text *Menu::getText()
{
    return _text;
}

void Menu::MoveUp()
{
    if (selectedItemIndex < 1)
    {
        selectedItemIndex = 1;
    }
    else if (selectedItemIndex > 1)
    {
        _text[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        _text[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex > numberOfItems)
    {
        selectedItemIndex = numberOfItems - 1;
    }
    else if (selectedItemIndex < numberOfItems - 1)
    {
        _text[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        _text[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

// sf::Texture Menu::getTexture()
// {
//     return _texture;
// }

// sf::Sprite Menu::getSprite()
// {
//     return _sprite;
// }