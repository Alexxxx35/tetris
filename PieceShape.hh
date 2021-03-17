#ifndef DEF_PIECECHAPE
#define DEF_PIECECHAPE
#include <SFML/Graphics.hpp>

class PieceShape
{
private:
    int _cell_size = 25;
    int _width = 10;
    int _height = 20;
    sf::RectangleShape _rect;
    sf::Vector2f _vect;

public:
    PieceShape();
    ~PieceShape();
    int getCellSize();
    int getWidth();
    int getHeight();
    void setCellSize(int newValue);
    void setWidth(int newValue);
    void setHeight(int newValue);
    sf::RectangleShape getRect();
    sf::Vector2f getVect();
    void setVect(sf::Vector2f newVect);
};

#endif