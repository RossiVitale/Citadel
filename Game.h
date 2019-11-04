
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
    sf::View view;
    bool navigating = false;
    sf::Vector2f oldPos;



    Game();
    void resizeView();
    void zoomView(int zoom);
};


#endif //CITADEL_GAME_H
