#ifndef GAMECORE
#define GAMECORE

#include <sstream>
#include <iomanip>
#include "Scene.hh"
#include "Mouvement.hh"
#include "Piece.hh"
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Text.hpp>






class GameCore {
    friend class Scene;

    public:
        /*** Constructeur de GameCore
         * Se charge n'initialiser les membres
         ***/
        GameCore();

        /*** Boucle principale du jeu ***/
        void Run();

    private:

        /*** Applique un mouvement sur la pièce actuelle avec rollback s'il y'a collision ***/
        void ApplyMove(Mouvement mouvement);

        /*** Appel de la méthode update de la scene et génération d'une nouvelle pièce si besoin ***/
        void Update(const sf::Time& dt);

        /*** Appel de la méthode Rotate de Piece avecc rollback s'il y'a collision ***/
        void RotatePiece();

        /*** Créer une nouvelle piece random  ***/
        void CreatePiece();
        void SavePiece();
        void SwapPiece();

        bool Collision(std::array<sf::Vector2i, 4> piece);

        bool IsOccupied(int x, int y);

        void HandleEvents();


        void Render();

        void Pause();

        void Mute();

        void SuperDown();





        sf::RenderWindow _renderWindow;
        sf::Texture _texture;
        sf::Texture _texture_background;
        sf::Sprite _sprite_background;
        sf::IntRect _rect_background;


        sf::Music _music;
        sf::Font _font;

        bool _paused;
        bool _musicMuted;
        bool _usedPower;

        sf::Text _pauseText;
        sf::Text _legendNextPiece;
        sf::Text _legendSavedSlot;



        sf::Text _Score_Title;
        sf::Text _Score;
        int _Score_int;

        sf::Text _nLineClearedText;
        sf::Text _nLineClearedValue;
        int _nLineCleared;

        sf::Text _levelText;
        sf::Text _levelValue;
        int _level;




        sf::Time _elapsedTime;
        sf::RectangleShape _separationLine;
        std::unique_ptr<Scene> _scene;
        std::unique_ptr<Piece> _piece;
        std::unique_ptr<Piece> _preview;
        std::unique_ptr<Piece> _savedPiece;

        int _ID;



};

#endif