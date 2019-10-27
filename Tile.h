#ifndef CITADELL_TILE_H
#define CITADELL_TILE_H

#include <SFML/Graphics.hpp>
#include "SFML/System.hpp"
#include "TextureManager.h"



class Tile{
public:
    sf::IntRect intRect{0,0,72,36};
    TextureManager* tex;
    sf::Texture texture;
    sf::Sprite sprite;
    TileType type;
    int tileLevel;
    int maxLevel;
    float axis;
    float ord;


};



/////////////////////////////////////////////////////////////////



class Terrain : public Tile{
public:
    TileType type;
    bool allowConstruction;

    explicit Terrain(TileType type, float axis, float ord);
};



/////////////////////////////////////////////////////////////////////



class Building : public Tile{
public:
    TileType type;

    explicit Building(TileType type, int tileLevel,  float axis, float ord);
};

#endif
