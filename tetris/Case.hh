#ifndef CASE
#define CASE


#include <SFML/Graphics/Sprite.hpp>

//Structure contenant la sprite de la case
struct CaseSprite{
    CaseSprite(sf::Texture& texture, int BLOCK_SIZE, int id);
    sf::Sprite sprite;
};

struct Case{
    //La copie d'une case, important pour implémenter la descente des cases après avoir clear une ligne 
    //( la case d'au dessus est affectée à la case en dessous)
    Case& operator=(const Case& Case);
    bool empty = true;
    bool display = true;
    CaseSprite* caseSprite = nullptr;
};


#endif