#ifndef CITADELL_TILE_H
#define CITADELL_TILE_H

#include <SFML/Graphics.hpp>
#include "SFML/System.hpp"
#include "TextureManager.h"


enum TileType {
    Plain, Water, Forest, Cityhall, Residential, Farm,
    Park, Commercial, WorkingZone, CleanEnergy, IndEnergy, EventZone, Decoration
};


class Tile {
protected:
    sf::IntRect intRect{0, 0, 72, 36};
    sf::FloatRect clickRect{};
    sf::Sprite sprite;
    TileType type;
    float axis;
    float ord;

public:
    void manageSprite(TextureManager &txm, const std::string &name);

    sf::IntRect &getIntRect();

    sf::FloatRect &getClickRect();

    sf::Sprite &getSprite();

    float getCoords(const std::string &coord);
};

/////////////////////////////////////////////////////////////////

class Terrain : public Tile {
private:
    bool allowConstruction;
public:
    Terrain(TileType type, float axis, float ord, TextureManager &txm);

    void reclaim(std::vector<Tile> &tileMap, TextureManager &txm);
};

/////////////////////////////////////////////////////////////////

class Building : public Tile {
private:
    int tileLevel;
    int maxLevel;
    int workers;
    int residents;
public:
    Building(TileType type, int tileLevel, float axis, float ord, TextureManager &txm);

    void dismantle(std::vector<Tile> &tileMap, TextureManager &txm);

    void upgrade();
};

#endif
