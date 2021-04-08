#include "Piece.hh"


#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>


/***
 *  Représentation 1D des coordonnées des blocs de chaque pièce/rotation
 *  [ 0   1     2   3]
 *  [ 4   5     6   7]
 *  [ 8   9     10  11]
 *  [ 12  13    14  15]
 ***/

unsigned int PiecesAllRotations[7][4][4]= {
    { {4,5,8,9},{4,5,8,9},{4,5,8,9},{4,5,8,9} } //Carré
    ,
    { {5,9,13,12},{10,9,8,4},{13,9,5,6},{8,9,10,14} } // L inverse 
    ,
    { {5,9,10,14},{10,9,13,12},{13,9,8,4},{8,9,5,6} } // Z
    ,
    { {5,9,8,12},{10,9,5,4},{13,9,10,6},{8,9,13,14} } // Z inverse
    ,
    { {5,8,9,10},{5,9,10,13},{8,9,10,13},{5,8,9,13} } // T
    ,
    { {5,9,13,14},{10,9,8,12},{13,9,5,4},{8,9,10,6} } // L
    ,
    { {1,5,9,13},{4,5,6,7},{1,5,9,13},{4,5,6,7} }  // |
};


Piece::Piece(sf::Texture &texture,int BLOCK_SIZE, int id)
: _position(sf::Vector2i{3, 0}), _rotation(0), _ID(id), _piece(),
 _sprite(texture, sf::IntRect{(id % 7 )* BLOCK_SIZE, 0, BLOCK_SIZE, BLOCK_SIZE}),
    BLOCK_SIZE(BLOCK_SIZE){
    _ID = _ID % 7;
    for(int i = 0; i < 4; ++i){
        _piece[i].x = PiecesAllRotations[_ID][0][i] % 4;
        _piece[i].y = PiecesAllRotations[_ID][0][i] / 4;
    }
}


void Piece::Rotate(){
    _oldPiece = _piece;
    _rotation= (_rotation+1)%4;
     for(int i = 0; i < 4; ++i){
         _piece[i].x =PiecesAllRotations[_ID][_rotation][i]%4;
         _piece[i].y =PiecesAllRotations[_ID][_rotation][i]/4;
     }
}

void Piece::Move(Mouvement mouvement) {

    switch (mouvement)
    {
    case Mouvement::Left:
        _position.x--;
        break;
    
    case Mouvement::Right:
        _position.x++;
        break;
       
    default:
         _position.y++;
    }
}


void Piece::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(int i = 0; i < 4; ++i){
        _sprite.setPosition((_piece[i].x * (float) BLOCK_SIZE) + (_position.x * (float) BLOCK_SIZE), (_piece[i].y * (float) BLOCK_SIZE) + (_position.y * (float) BLOCK_SIZE));
        target.draw(_sprite);
        
    }
}

std::array<sf::Vector2i, 4> Piece::GetPositions() const {
    std::array<sf::Vector2i, 4> blockPositions;
    for(int i = 0; i < 4; ++i){
        blockPositions[i] = sf::Vector2i{_piece[i].x + _position.x, _piece[i].y + _position.y };
    }
    return blockPositions;
}



std::array<sf::Vector2i, 4> Piece::GetFuturePositions(Mouvement mouvement) const {

    std::array<sf::Vector2i, 4> blocPositions;
    sf::Vector2i tmpPosition = _position;
    switch (mouvement)
    {
    case Mouvement::Left:
        tmpPosition.x--;
        break;
    
    case Mouvement::Right:
        tmpPosition.x++;
        break;
       
    default:
         tmpPosition.y++;
    }

    for(int i = 0; i < 4; ++i){
        blocPositions[i] = sf::Vector2i{_piece[i].x + tmpPosition.x, _piece[i].y + tmpPosition.y};
    }
    return blocPositions;
}


void Piece::Cancel() {
    _piece = _oldPiece;
    if(_rotation>0)
    _rotation--;
    else
    _rotation=3;
}

int Piece::GetID() {
    return _ID;
}

void Piece::SetPosition(const sf::Vector2i& position) {
    _position = position;
}