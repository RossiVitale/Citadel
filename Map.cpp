#include <fstream>
#include "Map.h"


Map::Map(const std::string &filename) {
    std::ifstream mapFile(filename);
    char character;
    float axis = 1000;
    float ord = 100;
    float i = 0;
    float ii = 0;
    mapSize = 0;
    tileMap.reserve(tilesOnMap);

    if (mapFile.is_open()) {
        while (!mapFile.eof()) {
            mapFile.get(character);
            switch (character) {
                case '0':
                    tileMap.push_back(Terrain(Plain, axis, ord, txm));
                    axis += 72;
                    mapSize++;
                    break;

                case '1':
                    tileMap.push_back(Terrain(Forest, axis, ord, txm));
                    axis += 72;
                    mapSize++;
                    break;

                case '2':
                    tileMap.push_back(Terrain(Water, axis, ord, txm));
                    axis += 72;
                    mapSize++;
                    break;

                case '3':
                    tileMap.push_back(Building(Cityhall, 1, axis, ord, txm));
                    axis += 72;
                    mapSize++;
                    break;

                case '\n':
                    if (ord < 532) {
                        i++;
                        axis = 1000 - (36 * i);
                    } else {
                        ii++;
                        axis = 136 + ((36 * ii));
                    }
                    ord += 18;
                    continue;

                case ' ':
                    continue;

                default:
                    std::cout << "error: chars not allowed found on " << filename << std::endl;
                    break;
            }
        }
    }
    checkMapSize(filename);
    mapFile.close();
}

void Map::checkMapSize(const std::string &filename) {
    if (mapSize != tilesOnMap) {
        std::cout << "error: too many tiles requested on map" << filename << std::endl;
    } else
        std::cout << std::endl << "success: map size match" << std::endl;
}

Tile &Map::getTileMapRef(int index) {
    return this->tileMap.at(index);
}
