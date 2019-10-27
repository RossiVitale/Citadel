
#ifndef CITADEL_GAME_H
#define CITADEL_GAME_H

#include "SFML/Graphics.hpp"
#include "Tile.h"


class Game {
public:

    sf::RenderWindow renderWindow;
    sf::IntRect intRect{0,0,72,36};
    sf::Clock clock;
    std::vector<Tile> tileMap;


    Game();
};


#endif //CITADEL_GAME_H
