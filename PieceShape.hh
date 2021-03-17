#ifndef DEF_PIECECHAPE
#define DEF_PIECECHAPE

class PieceShape
{
private:
    int _cell_size = 25;
    int _width = 10;
    int _height = 20;

public:
    PieceShape(/* args */);
    ~PieceShape();
    int getCellSize();
    int getWidth();
    int getHeight();
    void setCellSize(int newValue);
    void setWidth(int newValue);
    void setHeight(int newValue);
};

#endif