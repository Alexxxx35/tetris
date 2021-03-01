#ifndef DEF_PIECESHAPE
#define DEF_PIECESHAPE

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

    int _cell_size = 25;
    int _width = 10;
    int _height = 20;

public:
    PieceShape();
    ~PieceShape();
    int GetPieceCellSize();
    void SetPieceCellSize(int NewCellSize);
    int GetWidth();
    void SetWidth(int NewWidth);
    int GetHeight();
    void SetHeight(int NewHeight);
};


#endif