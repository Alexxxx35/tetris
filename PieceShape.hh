#ifndef DEF_PIECESHAPE
#define DEF_PIECESHAPE
//#include "AbstractEntity.hh"
#include <SFML/Graphics.hpp>
#include <vector>
class PieceShape
{
private:
    // enum _shape
    // {
    //     SHAPE_I,
    //     SHAPE_J,
    //     SHAPE_L,
    //     SHAPE_O,
    //     SHAPE_S,
    //     SHAPE_T,
    //     SHAPE_Z,
    // };

    int _patterns[7][4][4] =
        {
            {1, 0, 0, 0,
             1, 0, 0, 0,
             1, 0, 0, 0,
             1, 0, 0, 0},

            {1, 0, 0, 0,
             1, 1, 0, 0,
             0, 1, 0, 0,
             0, 0, 0, 0},

            {0, 1, 0, 0,
             1, 1, 0, 0,
             1, 0, 0, 0,
             0, 0, 0, 0},

            {1, 1, 0, 0,
             1, 1, 0, 0,
             0, 0, 0, 0,
             0, 0, 0, 0},

            {1, 0, 0, 0,
             1, 1, 0, 0,
             1, 0, 0, 0,
             0, 0, 0, 0},

            {1, 0, 0, 0,
             1, 0, 0, 0,
             1, 1, 0, 0,
             0, 0, 0, 0},

            {0, 1, 0, 0,
             0, 1, 0, 0,
             1, 1, 0, 0,
             0, 0, 0, 0},
    };
    std::vector<sf::Color> _listOfColors = {
        sf::Color::Green, sf::Color::Blue, sf::Color::Red, sf::Color::Yellow,
        sf::Color::White, sf::Color::Magenta, sf::Color::Cyan};

    float _cell_size = 25;
    float _width = 10;
    float _height = 20;
    sf::RectangleShape _size;
    sf::Vector2f _vector;
    sf::Color _color;
    double _X;
    double _Y;
    sf::RectangleShape _Shape;

public:
    PieceShape();
    ~PieceShape();
    double GetX();
    void SetX(double NewX);
    double GetY();
    void SetY(double NewY);
    // void Draw();
    // void Update();
    void ChangeShapeColor(sf::Color NewColor);
    sf::Color GetColor();
    void SetColor(sf::Color NewColor);
    sf::RectangleShape GetSize();
    void SetSize(float x, float y);
    sf::Vector2f GetVector();
    void SetVector(float x, float y);
    void SetSize(sf::Vector2f NewSize);
    float GetPieceCellSize();
    void SetPieceCellSize(float NewCellSize);
    float GetWidth();
    void SetWidth(float NewWidth);
    float GetHeight();
    void SetHeight(float NewHeight);
    sf::Color ChoosePieceShape();
    //sf::RectangleShape DefineShape();
    void DefineShape();
    sf::RectangleShape GetShape();
};

#endif