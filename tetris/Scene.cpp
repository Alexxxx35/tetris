#include <iostream>
#include <algorithm>
#include "Scene.hh"
#include "GameCore.hh"



int Scene::GetIndexFrom2DCoordinates(int x, int y) {
    return y * dimensions.x + x;
}

sf::Vector2i Scene::Get2DCoordinatesFromIndex(int index) {
    int x = dimensions.x % index;
    int y = index / dimensions.x;
    return sf::Vector2i(x,y);
}


Scene::Scene(int largeur_x, int longueur_y,int BLOCK_SIZE, GameCore& core) : core(core), cases(), casesSprite(), 
dimensions(sf::Vector2i(largeur_x,longueur_y)),yCleaned(), elapsedTime(0.f), isBusyCleaning(false), BLOCK_SIZE(BLOCK_SIZE){

    for(int x = 0; x < largeur_x; ++x){
        for(int y = 0; y < longueur_y; ++y){
            int map_index = GetIndexFrom2DCoordinates(x,y);
            cases[map_index] = std::make_unique<Case>();
        }
    }
    for(int id = 0; id < 7; ++id){
        casesSprite[id] = std::make_unique<CaseSprite>(core._texture,BLOCK_SIZE, id); 
    }
}

Scene::Scene(sf::Vector2i dimensions,int BLOCK_SIZE, GameCore& core) : core(core), cases(), casesSprite(), 
dimensions(dimensions),yCleaned(), elapsedTime(0.f), isBusyCleaning(false), BLOCK_SIZE(BLOCK_SIZE){

    for(int x = 0; x < dimensions.x; ++x){
        for(int y = 0; y < dimensions.y; ++y){
            int map_index = GetIndexFrom2DCoordinates(x,y);
            cases[map_index] = std::make_unique<Case>();
        }
    }
    for(int id = 0; id < 7; ++id){
        casesSprite[id] = std::make_unique<CaseSprite>(core._texture,BLOCK_SIZE, id);
    }
}

Scene::~Scene(){}

void Scene::Materialize(int id, std::array<sf::Vector2i, 4> piece) {
    core._usedPower=false;
    for (int i = 0; i < 4; ++i) {
        auto Case = GetCase(piece[i].x, piece[i].y); // on récupère la case de coordonnée (x,y)
        Case->empty = false;                         // la case devient occupée
        Case->caseSprite = casesSprite[id].get();    // la case prend le sprite du type de pièce
    }
}


void Scene::Draw(sf::RenderWindow &window) {
    //on parcourt tout le plateau
    for(int x = 0; x < dimensions.x; ++x){
        for(int y = 0; y < dimensions.y; ++y){

            auto Case = GetCase(x,y);                                                 // on récupère la case associée à la coordonnée x,y
            if(Case-> empty==false && Case->display==true)                            // Si la case n'est pas vide et qu'elle doit être affichée
            {
                Case->caseSprite->sprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE); // on positionne le sprite au bon endroit
                window.draw(Case->caseSprite->sprite);                                // on dessine le sprite sur la fenetre
            }
        }
    }
}


Case* Scene::GetCase(int x, int y) {
    int index = GetIndexFrom2DCoordinates(x,y);
    return cases[index].get();
}


void Scene::Reset() {
    core._Score_int=0;
    core._nLineCleared=0;
    core._level=0;
    core._savedPiece.reset(nullptr);
    for(int x = 0; x < dimensions.x; ++x){
        for(int y = 0; y < dimensions.y; ++y) {
            auto Case = GetCase(x,y);
            Case->empty = true;
            Case->display = true;
            Case->caseSprite = nullptr;
        }
    }
}


void Scene::AddCompletedLines() {
    if(isBusyCleaning) return;
    int countClearedLines = 0;

    for (int y = dimensions.y - 1; y > 0; --y) {
        int counter = 0;

        for (int x = 0; x < dimensions.x; ++x) {
            auto Case = GetCase(x, y);
            if (!Case->empty) {
                counter++;
            }
            if (counter == dimensions.x) { 
                yCleaned.push_back(y);
                isBusyCleaning = true;
                countClearedLines++;
            }
        }
        counter = 0;
    }
    std::sort(yCleaned.begin(), yCleaned.end(), [](int a, int b) { return a < b; }); // Sort en ordre croissant
}

void Scene::CleanLines() {
    if (yCleaned.empty()) return;
    int numberOfLines = yCleaned.size();
    core._nLineCleared+=numberOfLines;
    switch (numberOfLines)
    {
    case 1:
        core._Score_int+=40;
        break;
    case 2:
        core._Score_int+=100;
        break;
    case 3:
        core._Score_int+=300;
        break;
    case 4:
        core._Score_int+=1200;
        break;
    default:
        break;
    }


    for (int i : yCleaned) { // En partant de la plus haute ligne à supprimer
        for (int y = i; y >= 0; --y) { // Du bas vers le haut

            for(int x = 0; x < dimensions.x; ++x){ // pour chaque colonne
                if(y-1 < 0) continue;
                *GetCase(x,y) = *GetCase(x,y-1);
            }
        }
    }
    yCleaned.clear();
    isBusyCleaning = false;
}


void Scene::Update(const sf::Time& dt) {
    AddCompletedLines();
    if(isBusyCleaning){
        elapsedTime += dt.asSeconds();
        Blink();

        if(elapsedTime > 0.6f){
            elapsedTime = 0.f;
            CleanLines();
        }
    }
}


bool Scene::IsOccupied(std::array<sf::Vector2i, 4> piece) {
    for(int i = 0; i < 4; ++i) {
        auto  Case = GetCase(piece[i].x, piece[i].y);
        if (!Case->empty) {
            return true;
        }
    }
    return false;
}

void Scene::Blink() {
    int num = int(elapsedTime * 5.f);
    for (int y : yCleaned) { // la ligne des cases à faire clignoter
        for (int x = 0; x < dimensions.x; ++x) { // toute les colonnes 
            GetCase(x,y)->display = (num % 2 != 0); // on alterne entre display= true et display = false
        }
    }
}

bool Scene::IsBusy() { 
    return isBusyCleaning;
}



