
#ifndef CITADEL_GAME_H
#define CITADEL_GAME_H

#include "SFML/Graphics.hpp"
#include "Map.h"


class Game {
private:
    sf::RenderWindow renderWindow;
    sf::Clock clock;
    sf::View view;
    sf::Vector2f oldPos;

public:
    Game();
    void resizeView();
    void zoomView(int zoom);

    void animateWorld(Map &map);
};

#endif //CITADEL_GAME_H