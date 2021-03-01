#ifndef DEF_ENTITYFACTORY
#define DEF_ENTITYFACTORY
#include "AbstractEntity.hh"
#include "PieceEntity.hh"

class EntityFactory
{
private:
    /* data */
public:
    EntityFactory(/* args */);
    ~EntityFactory();
    CreatePiece()
    {
        return new PieceEntity(x,y,PieceShape);
    }
};

#endif