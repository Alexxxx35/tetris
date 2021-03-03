#ifndef DEF_PIECESHAPE
#define DEF_PIECESHAPE
#include <SFML/Graphics.hpp>

class PieceShape
{
private:
    enum _shape
    {
        SHAPE_I,
        SHAPE_J,
        SHAPE_L,
        SHAPE_O,
        SHAPE_S,
        SHAPE_T,
        SHAPE_Z,
    };

    float _cell_size = 25;
    float _width = 10;
    float _height = 20;
    sf::RectangleShape _shape;
    sf::Vector2f _vector;
    sf::Color _color;

public:
    PieceShape();
    ~PieceShape();
    void ChangeShapeColor(sf::Color NewColor);
    sf::Color GetColor();
    void SetColor(sf::Color NewColor);
    sf::RectangleShape GetShape();
    void SetShape(float x, float y);
    sf::Vector2f GetVector();
    void SetVector(float x, float y);
    void SetShape(sf::Vector2f NewShape);
    float GetPieceCellSize();
    void SetPieceCellSize(float NewCellSize);
    float GetWidth();
    void SetWidth(float NewWidth);
    float GetHeight();
    void SetHeight(float NewHeight);
};

#endif