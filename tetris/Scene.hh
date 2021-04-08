#ifndef SCENE
#define SCENE

#include "list"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>
#include <array>
#include <map>
#include "Case.hh"


class GameCore;

class Scene{
    public :
        //Une scene est unique, on enlève la possibilité de la copier
        Scene(const Scene& other) = delete;
        Scene& operator= (const Scene& other) = delete;

        /*** Constructeur de la scene
         *  Param: int largeur,
         *  Param: int longueur,
         *  Param: int taille des blocs composant une pièce,
         *  Param: GameCore& référence au moteur du jeu utile pour lui transmettre des informations sur l'êtat du plateau
         ***/
        Scene(int largeur_x, int longueur_y, int BLOCK_SIZE, GameCore& core);

        /*** Constructeur de la scene
         *  Param: Dimensions (sf::Vector2i)
         *  Param: Ref GameCore utile pour transmettre des informations au moteur du jeu
         ***/
        Scene(sf::Vector2i dimensions, int BLOCK_SIZE, GameCore& core);
        
        //Destructeur
        ~Scene();
        
        // Update le plateau et applique les évènements dépendant du temps comme le clignotement
        void Update(const sf::Time& dt);

        //Nettoie tout le plateau (détruit toutes les pièces et blocs)
        void Reset();

        //Fonction appellée lorsque le core detecte que la pièce ne peut pas aller plus loin : toute les cases occupées par la pièce sont alors mis à occupé
        void Materialize(int id, std::array<sf::Vector2i, 4> piece);

        // Test si l'une des positions en paramètre est occupée
        bool IsOccupied(std::array<sf::Vector2i, 4> piece);

        // Dessine le plateau et les pièces
        void Draw(sf::RenderWindow& window);

        // indique si le plateau est en cours de suppression d'une pièce ( pour ne pas générer une nouvelle pièce tant que ce n'est pas fini)
        bool IsBusy();

        // retourne la case de coordonnée x y
        Case* GetCase(int x, int y);

    private:

        //Convertit coordonnée 2D en coordonnée 1D : (x,y) => (y*largeur + x)
        int GetIndexFrom2DCoordinates(int x, int y);

        //Convertit coordonnée 1D en coordonnée 2D : index => (x=largeur%index) (y=index/largeur)
        sf::Vector2i Get2DCoordinatesFromIndex(int index);

        //Réarange les pièces après suppression d'une ligne en les descandant d'une case
        void CleanLines();

        // Marque les lignes remplies pour qu'elles soient supprimées
        void AddCompletedLines();

        //Clignotement (Alterne la valeur display des cases)
        void Blink();


        /************************* ATTRIBUTS ***************************/

        // Référence de Game pour utiliser ses méthodes et attributs
        GameCore& core;


        //Index des cases - > Etat de la case
        std::map<int, std::unique_ptr<Case>> cases;

        // Contient les 7 types de cases
        std::map<int, std::unique_ptr<CaseSprite>> casesSprite;
        
        //Taille du plateau (10,18)
        sf::Vector2i dimensions;

        //Stock la position en y des lignes complétées à supprimer
        std::vector<int> yCleaned;

        // Temps écoulé
        float elapsedTime;

        //true si certaines cases sont entrain de clignoter
        bool isBusyCleaning;

        const int BLOCK_SIZE;


};

#endif