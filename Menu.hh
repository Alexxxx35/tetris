#ifndef DEF_MENU
#define DEF_MENU
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "WindowManager.hh"
class Menu
{
private:
    sf::Font _font;
    sf::Font _titleFont;
    sf::Text _text[4];
    unsigned int _width;  //normally take value of window
    unsigned int _height; //normally take value of window
    int const numberOfItems = 4;
    int selectedItemIndex = 1;
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::Music _music;
    sf::Vector2f _window_size;
    bool _underligned = false;

public:
    void unUnderlignText(int i);
    void underlignText(int i);
    void launchMusic(std::string music_path);
    void stopMusic();
    void pauseMusic();
    void relaunchMusic();
    int getSelectedItemIndex();
    sf::Texture getTexture();
    sf::Sprite getSprite();
    void draw(sf::RenderWindow &window);
    sf::Vector2f getTextPosition(int i);
    void MoveUp();
    void MoveDown();
    Menu(sf::RenderWindow &window);
    ~Menu();
};

#endif