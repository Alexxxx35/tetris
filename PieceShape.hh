#ifndef DEF_PIECESHAPE
#define DEF_PIECESHAPE
#include <SFML/Graphics.hpp>

class PieceShape
{
private:
    float _cell_size = 25.0;
    float _width = 10.0;
    float _height = 20.0;
    sf::RectangleShape _rect;
    sf::Vector2f _vect;

public:
    PieceShape();
    ~PieceShape();
    float getCellSize();
    float getWidth();
    float getHeight();
    void setCellSize(float newValue);
    void setWidth(float newValue);
    void setHeight(float newValue);
    sf::RectangleShape getRect();
    sf::Vector2f getVect();
    void setVect(sf::Vector2f newVect);
};

#endif