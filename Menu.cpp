#include "Menu.hh"
#include "WindowManager.hh"
#include "iostream"
Menu::Menu(sf::RenderWindow &window)
{
    _width = window.getSize().x;
    _height = window.getSize().y;
    font.loadFromFile("arial.ttf");
    if (!font.loadFromFile("arial.ttf"))
    {
        throw 1;
    }

    for (int i = 0; i < numberOfItems; i++)
    {
        if (i == 0)
        {
            _text[i].setString("Start");
        }
        if (i == 1)
        {
            _text[i].setString("Option");
        }
        if (i == 2)
        {
            _text[i].setString("Exit");
        }
        _text[i].setFont(font);
        _text[i].setFillColor(sf::Color::White);
        _text[i].setPosition(sf::Vector2f(_width / 2, (i * _height / numberOfItems)));
        std::cout << (i * _height / numberOfItems) << std::endl;
    }
}

void Menu::draw(sf::RenderWindow &window)
{

    for (int i = 0; i < numberOfItems; i++)
    {

        window.draw(_text[i]);
    }
}

sf::Text *Menu::getText()
{
    return _text;
}

void Menu::MoveUp()
{
    if (selectedItemIndex > 0)
    {
        if (selectedItemIndex < 0)
        {
            selectedItemIndex = 0;
        }

        _text[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        _text[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex > numberOfItems)
    {
        if (selectedItemIndex > numberOfItems)
        {
            selectedItemIndex = numberOfItems;
        }
        _text[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        _text[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}
Menu::~Menu()
{
}
