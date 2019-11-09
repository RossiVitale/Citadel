#include "Tile.h"


void Tile::manageSprite(TextureManager &txm, const std::string &name) {
    sprite.setTexture(txm.getRefTex(name));
    sprite.setPosition(this->axis, this->ord);
    sprite.setTextureRect(intRect);
}

sf::FloatRect &Tile::getClickRect() {
    return this->clickRect;
}

sf::IntRect &Tile::getIntRect() {
    return this->intRect;
}


float Tile::getCoords(const std::string &coord) {
    if (coord == "axis")
        return this->axis;
    else if (coord == "ord")
        return this->ord;
    else
        std::cout << "error: only -axis- or -ord- request allowed" << std::endl;
}

sf::Sprite &Tile::getSprite() {
    return this->sprite;
}

Terrain::Terrain(TileType type, float axis, float ord, TextureManager &txm) {
    this->axis = axis;
    this->ord = ord;
    this->type = type;

    switch (type) {
        case Plain: {
            manageSprite(txm, "Plain");
            allowConstruction = true;
            break;
        }

        case Forest: {
            manageSprite(txm, "Forest");
            this->allowConstruction = false;
            break;
        }

        case Water: {
            manageSprite(txm, "Water");
            this->allowConstruction = false;
            break;
        }

        default : {
            std::cout << "error: not a terrain" << std::endl;
            break;
        }
    }
    clickRect = {this->axis + 18, this->ord + 9, 36, 18};
}

void Terrain::reclaim(std::vector<Tile> &tileMap, TextureManager &txm) {
    if (type == Forest || type == Water)
        //costo e inquinamento e felicità
        tileMap.push_back(Terrain(Plain, this->axis, this->ord, txm));
}



////////////////////////////////////////////////////////////////////////////////////////////


Building::Building(TileType type, int tileLevel, float axis, float ord, TextureManager &txm) {
    this->axis = axis;
    this->ord = ord;
    this->type = type;
    this->tileLevel = tileLevel;

    switch (type) {
        case Cityhall:
            this->maxLevel = 1;
            manageSprite(txm, "Cityhall");
            break;

        case Residential:
            this->maxLevel = 3;
            if (tileLevel == 1)
                manageSprite(txm, "Residential1");
            else if (tileLevel == 2)
                manageSprite(txm, "Residential2");
            else if (tileLevel == 3)
                manageSprite(txm, "Residential3");
            break;

        case Farm:
            this->maxLevel = 3;
            if (tileLevel == 1)
                manageSprite(txm, "Farm1");
            else if (tileLevel == 2)
                manageSprite(txm, "Farm2");
            else if (tileLevel == 3)
                manageSprite(txm, "Farm3");
            break;

        case Park:
            this->maxLevel = 1;
            manageSprite(txm, "Park");
            break;

        case Commercial:
            this->maxLevel = 3;
            if (tileLevel == 1)
                manageSprite(txm, "Commercial1");
            else if (tileLevel == 2)
                manageSprite(txm, "Commercial2");
            else if (tileLevel == 3)
                manageSprite(txm, "Commercial3");
            break;

        case WorkingZone:
            this->maxLevel = 3;
            if (tileLevel == 1)
                manageSprite(txm, "Work1");
            else if (tileLevel == 2)
                manageSprite(txm, "Work2");
            else if (tileLevel == 3)
                manageSprite(txm, "Work3");
            break;

        case CleanEnergy:
            this->maxLevel = 3;
            if (tileLevel == 1)
                manageSprite(txm, "CleanEnergy1");
            else if (tileLevel == 2)
                manageSprite(txm, "CleanEnergy2");
            else if (tileLevel == 3)
                manageSprite(txm, "CleanEnergy3");
            break;

        case IndEnergy:
            this->maxLevel = 3;
            if (tileLevel == 1)
                manageSprite(txm, "IndEnergy1");
            else if (tileLevel == 2)
                manageSprite(txm, "IndEnergy2");
            else if (tileLevel == 3)
                manageSprite(txm, "IndEnergy3");
            break;


        case EventZone:   //livello 1: static        livello 2: dinamic
            this->maxLevel = 2;
            if (tileLevel == 1)
                manageSprite(txm, "EventStatic");
            else if (tileLevel == 2)
                manageSprite(txm, "EventAnim");
            break;


        case Decoration:
            this->maxLevel = 1;
            manageSprite(txm, "Decoration");
            break;

        default :
            std::cout << "error: not a terrain" << std::endl;
            break;

    }
    clickRect = {this->axis + 18, this->ord + 9, 36, 18};

}

void Building::upgrade() {
    if (tileLevel != maxLevel) {
        //aumenta di livello
    }
}

void Building::dismantle(std::vector<Tile> &tileMap, TextureManager &txm) {
    if (type != Cityhall)
        //costo e attributi vari
        tileMap.push_back(Terrain(Plain, this->axis, this->ord, txm));
}