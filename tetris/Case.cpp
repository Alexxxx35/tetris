#include "Case.hh"

CaseSprite::CaseSprite(sf::Texture& texture ,int BLOCK_SIZE, int id) {
    // x0,y0, width, heigth
    sf::IntRect rect{(id % 7) * BLOCK_SIZE, 0, BLOCK_SIZE,BLOCK_SIZE};
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
}

Case& Case::operator=(const Case& Case) {
    this->empty = Case.empty;
    this->display = Case.display;
    this-> caseSprite= Case.caseSprite;
    return *this;
}