#ifndef CITADELL_TEXTUREMANAGER_H
#define CITADELL_TEXTUREMANAGER_H

#include <iostream>
#include "SFML/Graphics.hpp"

enum TileType{ Plain, Water, Forest, Cityhall, Residential, Farm,
    Park, Commercial, WorkingZone, CleanEnergy, IndEnergy, EventZone, Decoration};

class TextureManager {
public:
    std::vector<sf::Texture> TextureAtlas;
    sf::Texture texture;


    explicit TextureManager(TileType type);

};

#endif