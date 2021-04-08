#include "GameCore.hh"
#include <SFML/Window/Event.hpp>

#include <iostream>
#include <string>
#include <random>
#include <algorithm>

const unsigned int LARGEUR=10;
const unsigned int LONGUEUR =18;
const unsigned int BLOCK_SIZE= 32;
const char* spriteFile = "src/Block_32x32.png";
const char* musicFile = "src/tetris-game-boy.wav";
const char* spriteFile_Background = "src/tetris_background.jpg";



GameCore::GameCore() : 
    _renderWindow{sf::VideoMode{ LARGEUR* BLOCK_SIZE + (BLOCK_SIZE*10), BLOCK_SIZE * LONGUEUR}, "Tetris"},                     
    _texture(), _music(), _separationLine(), _piece(nullptr),_font(), _Score_Title(), _Score(), _Score_int(0),
    _preview(nullptr), _scene(), _elapsedTime(sf::Time::Zero) , _paused(false),_pauseText(),_savedPiece(nullptr), _usedPower(false),
    _legendNextPiece(), _legendSavedSlot() , _nLineClearedText() , _nLineClearedValue(), _nLineCleared(0) , _musicMuted(false),
    _level(0),_levelText(),_levelValue(),_texture_background()
{

    srand((unsigned int)time(NULL));
    _ID= rand()%8;
    _separationLine.setSize(sf::Vector2f{5.f, (float) BLOCK_SIZE * (float) LONGUEUR});
    _separationLine.setPosition(sf::Vector2f{(float) LARGEUR * BLOCK_SIZE, 0});
    _separationLine.setFillColor(sf::Color::White);

    if(!_font.loadFromFile("src/vertiup2.ttf")){
        std::cout << "Le chargement de la police d'écriture a échoué" << std::endl;
    }
    
    _legendNextPiece.setFont(_font);
    _legendNextPiece.setString("Next");
    _legendNextPiece.setPosition(sf::Vector2f{LARGEUR*BLOCK_SIZE+BLOCK_SIZE*5,BLOCK_SIZE*3});
    _legendNextPiece.setFillColor(sf::Color::White);

    _legendSavedSlot.setFont(_font);
    _legendSavedSlot.setString("Saved");
    _legendSavedSlot.setPosition(sf::Vector2f{LARGEUR*BLOCK_SIZE+BLOCK_SIZE*5,BLOCK_SIZE*7});
    _legendSavedSlot.setFillColor(sf::Color::White);

    _pauseText.setFont(_font);
    _pauseText.setString("Paused");
    _pauseText.setPosition(sf::Vector2f{(float) LARGEUR/2 *BLOCK_SIZE,(float) LONGUEUR/2 * BLOCK_SIZE});
    _pauseText.setFillColor(sf::Color::White);

    _Score_Title.setCharacterSize(20);
    _Score_Title.setFont(_font);
    _Score_Title.setString("Score");
    _Score_Title.setPosition(sf::Vector2f{ (float) LARGEUR * BLOCK_SIZE + .5 * BLOCK_SIZE, (float) LONGUEUR  * BLOCK_SIZE * .6});
    _Score_Title.setFillColor(sf::Color::Red);
    
    _Score.setFont(_font); 
    _Score.setCharacterSize(20);
    _Score.setString("00000");
    _Score.setPosition(sf::Vector2f{ (float) LARGEUR * BLOCK_SIZE + 1 * BLOCK_SIZE, (float) LONGUEUR  * BLOCK_SIZE * .65});
    _Score.setFillColor(sf::Color::Red);

    _nLineClearedText.setFont(_font);
    _nLineClearedText.setCharacterSize(20);
    _nLineClearedText.setString("Lines Cleared");
    _nLineClearedText.setPosition(sf::Vector2f{ (float) LARGEUR * BLOCK_SIZE + 2 * BLOCK_SIZE, (float) LONGUEUR  * BLOCK_SIZE * 0.8});
    _nLineClearedText.setFillColor(sf::Color::Red);
    
    _nLineClearedValue.setFont(_font);
    _nLineClearedValue.setCharacterSize(20);
    _nLineClearedValue.setString(std::to_string(_nLineCleared));
    _nLineClearedValue.setPosition(sf::Vector2f{ (float) LARGEUR * BLOCK_SIZE + 5 * BLOCK_SIZE, (float) LONGUEUR  * BLOCK_SIZE * 0.85});
    _nLineClearedValue.setFillColor(sf::Color::Red);

    _levelText.setFont(_font);
    _levelText.setCharacterSize(20);
    _levelText.setString("Level");
    _levelText.setPosition(sf::Vector2f{ (float) LARGEUR * BLOCK_SIZE + 5 * BLOCK_SIZE, (float) LONGUEUR  * BLOCK_SIZE * .6});
    _levelText.setFillColor(sf::Color::Red);

    _levelValue.setFont(_font);
    _levelValue.setCharacterSize(20);
    _levelValue.setString(std::to_string(_level));
    _levelValue.setPosition(sf::Vector2f{ (float) LARGEUR * BLOCK_SIZE + 5 * BLOCK_SIZE, (float) LONGUEUR  * BLOCK_SIZE * .65});
    _levelValue.setFillColor(sf::Color::Red);

    if(!_texture_background.loadFromFile(spriteFile_Background)){
        std::cout << "Le chargement du sprite Background a échoué" << std::endl;
    }
    sf::IntRect rect{170, 100, BLOCK_SIZE*LARGEUR,BLOCK_SIZE*LONGUEUR};
    _sprite_background.setTexture(_texture_background);
    _sprite_background.setTextureRect(rect);


    
    if(!_texture.loadFromFile(spriteFile)){
        std::cout << "Le chargement des sprites des pièces a échoué" << std::endl;
    }

    if (!_music.openFromFile(musicFile)){
        std::cout << "Le chargement de la musique a échoué" << std::endl;
    }
       
    _scene = std::make_unique<Scene>(sf::Vector2i{(int) LARGEUR, (int) LONGUEUR},BLOCK_SIZE, *this);
    CreatePiece();
    
}





void GameCore::Run() {
    
    _music.play();
    sf::Clock clock;
    sf::Time deltaTime{sf::Time::Zero};

    while(_renderWindow.isOpen()){

        sf::Time trigger{sf::seconds(std::max(0.3,1-(0.1*_level)))};
        deltaTime = clock.restart();
        HandleEvents();
        if (!_paused){
            _elapsedTime += deltaTime;
            Update(deltaTime);
            if(_elapsedTime > trigger) {
                _elapsedTime = sf::Time::Zero;
                ApplyMove(Mouvement::Down);
            }
        }

        Render();
    }
}


void GameCore::Update(const sf::Time &dt) {
    _scene->Update(dt);
    _level = _nLineCleared/3;

    _nLineClearedValue.setString(std::to_string(_nLineCleared));
    _Score.setString(std::to_string(_Score_int));
    _levelValue.setString(std::to_string(_level));
    

    if(!_piece) {
        if(_scene->IsBusy()){
            return;
        }
        CreatePiece();
    }
}

void GameCore::RotatePiece() {
    if(!_piece) return;

    _piece->Rotate(); 
    if(Collision(_piece->GetPositions())){
        _piece->Cancel();
    }
    
}

void GameCore::Pause(){
    _paused= !_paused;
    if(_paused){
        _music.pause();
    }
    else _music.play();
}


void GameCore::Mute(){
    if(_musicMuted) {
        _music.play();
        _musicMuted=false;
    }else{
        _music.pause();
        _musicMuted=true;
    }
}

void GameCore::HandleEvents() {
    sf::Event e;
    while (_renderWindow.pollEvent(e)) {
        if (e.type == sf::Event::Closed) _renderWindow.close();
        else if (e.type == sf::Event::KeyPressed) {
            if (!_paused&&e.key.code == sf::Keyboard::Down) {
                ApplyMove(Mouvement::FastDown);
            } else if (!_paused&&e.key.code == sf::Keyboard::Right) {
                ApplyMove(Mouvement::Right);
            } else if (!_paused&&e.key.code == sf::Keyboard::Left) {
                ApplyMove(Mouvement::Left);
            } else if (!_paused&&e.key.code == sf::Keyboard::Space){
                SuperDown();
            } else if (!_paused&&e.key.code == sf::Keyboard::R) {
                RotatePiece();
            } else if (e.key.code == sf::Keyboard::P) {
                Pause();
                
            } else if ( !_usedPower && e.key.code == sf::Keyboard::S){
                if(!_savedPiece){
                    SavePiece();
                }
                else{
                    SwapPiece();
                }
            } else if (e.key.code == sf::Keyboard::M){
                Mute();
            }
        }
    }
}

void GameCore::Render() {
    _renderWindow.clear(sf::Color::Black);
    _renderWindow.draw(_sprite_background);
    _scene->Draw(_renderWindow);
    if(_piece) _renderWindow.draw(*_piece);
    if(_savedPiece) _renderWindow.draw(*_savedPiece);
    _renderWindow.draw(*_preview);
    _renderWindow.draw(_separationLine);
    _renderWindow.draw(_Score_Title);
    _renderWindow.draw(_legendNextPiece);
    _renderWindow.draw(_legendSavedSlot);
    _renderWindow.draw(_Score);
    _renderWindow.draw(_nLineClearedText);
    _renderWindow.draw(_nLineClearedValue);
    _renderWindow.draw(_levelText);
    _renderWindow.draw(_levelValue);
    
    if(_paused) _renderWindow.draw(_pauseText);
    _renderWindow.display();

}

void GameCore::ApplyMove(Mouvement mouvement) {
    if(!_piece) return;

    if(!Collision(_piece->GetFuturePositions(mouvement))){
        _piece->Move(mouvement);
    }
    else{
        if(mouvement == Mouvement::Down || mouvement == Mouvement::FastDown) {
            int id = _piece->GetID();
            _scene->Materialize(id, _piece->GetPositions());
            _piece.reset(nullptr);
        }
    }
}

bool GameCore::Collision(std::array<sf::Vector2i, 4> piece) {
    for(int i = 0; i < 4; ++i){
        if(piece[i].x < 0 ||piece[i].x >= LARGEUR || piece[i].y >= LONGUEUR || IsOccupied(piece[i].x, piece[i].y))
            return true;
    }
    return false;
}

bool GameCore::IsOccupied(int x, int y) {
    return !_scene->GetCase(x,y)->empty;
}

void GameCore::CreatePiece() {
   _piece.reset(new Piece{_texture,BLOCK_SIZE, _ID});

   if(_scene->IsOccupied(_piece->GetPositions())){
        _scene->Reset();
    }
    _ID=rand()%8;
    _preview.reset(new Piece{_texture,BLOCK_SIZE, _ID});
    _preview->SetPosition(sf::Vector2i{11, 1});
}


void GameCore::SwapPiece(){
    _ID= _savedPiece->GetID();
    _savedPiece.swap(_piece);
    _savedPiece->SetPosition(sf::Vector2i{11,6});
    _usedPower=true;
    CreatePiece();

}

void GameCore::SavePiece(){
    _savedPiece.swap(_piece);
    _savedPiece->SetPosition(sf::Vector2i{11,6});
    CreatePiece();
    _usedPower= true;

}

void GameCore::SuperDown(){
    while(_piece) ApplyMove(Mouvement::FastDown);
}