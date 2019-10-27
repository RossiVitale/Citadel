#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.h"
#include "Tile.h"
#include "Map.h"

#define tilesOnMap 625

Game::Game() {
    tileMap.reserve(tilesOnMap);
    renderWindow.create(sf::VideoMode(4000, 2000), "Citadel", sf::Style::Default);
    renderWindow.setFramerateLimit(60);
    renderWindow.clear();

    Tile* tile = nullptr;
    Map map(&tileMap, tile);

    sf::Event event{};

    while (renderWindow.isOpen()){
        while (renderWindow.pollEvent(event)){
            if (event.type == sf::Event::EventType::Closed)
                renderWindow.close();
        }
        if (clock.getElapsedTime().asSeconds() > 0.5f){
            if (intRect.left == 72*5) {
                intRect.left = 0;
            }
            else {
                intRect.left += 72;
            }
            for (int i=0; i<tilesOnMap; i++){
                tileMap.at(i).sprite.setTextureRect(intRect);
            }
            clock.restart();
        }
        for (int i=0; i<tilesOnMap; i++){
            renderWindow.draw(tileMap.at(i).sprite);
        }
        renderWindow.display();
    }
}