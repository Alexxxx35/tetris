#ifndef PIECE
#define PIECE

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <array>
#include "Mouvement.hh"


class Piece :  public sf::Drawable{
    public:

        /*** Constructeur d'une Piece
         *  Param: sf::Texture& texture,
         *  Param: int taille des blocs composant une pièce,
         *  Param: int id
         ***/
        Piece(sf::Texture& texture,int BLOCK_SIZE, int id);
        ~Piece(){};


        /*** Applique le mouvement passé en paramètre
         * Param: Mouvement mouvement le pièce ( gauche, droit , bas)
         ***/
        void Move(Mouvement mouvement);

        /*** Applique une rotation dans le sens des aiguilles d'une montre
         *  Toute les rotations possibles sont pré-stockés
         ***/
        void Rotate();
        
        /*** Retourne à la position et rotation précédant le dernier mouvement ***/
        void Cancel();

        /*** Change la position de la pièce ***/
        void SetPosition(const sf::Vector2i& position);

        /*** Renvoie la positions de chaque bloc composant la pièce ***/
        std::array<sf::Vector2i, 4> GetPositions() const;

        /*** Renvoie la positions de chaque bloc composant la pièce après l'application d'un mouvement ***/
        std::array<sf::Vector2i, 4> GetFuturePositions(Mouvement mouvement) const;

        /*** Renvoie l'id ***/
        int GetID();


    private:

        /*** Implémentation de la methode draw (héritage de drawable) ***/
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        /*** Position du bloc central de la pièce***/
        sf::Vector2i _position;

        /*** Rotation actuelle de la pièce [0,3] ***/
        int _rotation;

        /*** Id de la pièce ***/
        int _ID;

        /*** Positions des blocs composant la pièce***/
        std::array<sf::Vector2i, 4> _piece;

        /*** Positions des blocs composant la pièce avant le dernier mouvement***/
        std::array<sf::Vector2i, 4> _oldPiece;

        /*** Sprite de la pièce ***/
        mutable sf::Sprite _sprite;
        int BLOCK_SIZE;


};


#endif