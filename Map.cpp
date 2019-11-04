#include <fstream>
#include "Map.h"

Map::Map(std::vector<Tile> *tileMap, Tile*tile) {
std::ifstream mapFile("map.txt");
char character;
float axis=1000;
float ord=100;
float i=0;
float ii=0;

if(mapFile.is_open()) {
    while (!mapFile.eof()){
        mapFile.get(character);
        switch (character) {
                case '0':
                    tile = new Terrain(Plain, axis, ord);
                    tileMap->push_back(*tile);
                    axis += 72;
                    break;

                case '1':
                    tile = new Terrain(Forest, axis, ord);
                    tileMap->push_back(*tile);
                    axis += 72;
                    break;

                case '2':
                    tile = new Terrain(Water, axis, ord);
                    tileMap->push_back(*tile);
                    axis += 72;
                    break;

                case '3':
                    tile = new Building(Cityhall, 1, axis, ord);
                    tileMap->push_back(*tile);
                    axis += 72;
                    break;

                case '\n':
                    if(ord<532) {
                        i++;
                        axis = 1000 - (36 * i);
                    }else {
                        ii++;
                        axis = 136 + ((36*ii));
                    }
                    ord += 18;
                    continue;


        }
        }
    }
mapFile.close();
}