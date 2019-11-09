#ifndef CITADEL_MAP_H
#define CITADEL_MAP_H

#include <vector>
#include "Tile.h"

#define tilesOnMap 625

class Map {
private:
    std::vector<Tile> tileMap;
    TextureManager txm;
    int mapSize;

public:
    explicit Map(const std::string &filename);

    Tile &getTileMapRef(int index);

    void checkMapSize(const std::string &filename);
};

#endif //CITADEL_MAP_H