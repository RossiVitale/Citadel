#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.h"
#include "Tile.h"
#include "Map.h"

#define tilesOnMap 625


Game::Game() {
    tileMap.reserve(tilesOnMap);
    renderWindow.create(sf::VideoMode(2048, 1536), "Citadel", sf::Style::Default);
    renderWindow.setFramerateLimit(60);
    view.setCenter(1000, 532);
    view.setSize(500,500);
    renderWindow.clear();


    Tile* tile = nullptr;
    Map map(&tileMap, tile);

    sf::Event event{};

    while (renderWindow.isOpen()){
        while (renderWindow.pollEvent(event)){
            if (event.type == sf::Event::EventType::Closed)
                renderWindow.close();
            if(event.type== sf::Event::EventType::Resized)
                resizeView();
            if (event.type == sf::Event::MouseWheelMoved)
                zoomView(event.mouseWheel.delta);
            if(event.type == sf::Event::MouseButtonPressed)
                if (event.mouseButton.button == sf::Mouse::Right) {
                    navigating = true;
                    oldPos = renderWindow.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                }
            if (event.type == sf::Event::MouseButtonReleased)
                if (event.mouseButton.button == sf::Mouse::Right)
                    navigating = false;
            if (event.type == sf::Event::MouseMoved){
                if (navigating) {  //se non si sta premendo il tasto destro del mouse ignora il movimento
                    const sf::Vector2f newPos = renderWindow.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
                    const sf::Vector2f deltaPos = oldPos - newPos;
                    view.setCenter(view.getCenter() + deltaPos);
                    renderWindow.clear();
                    renderWindow.setView(view);
                    oldPos = renderWindow.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
                }
            }
            if (event.type == sf::Event::MouseButtonPressed)
                if(event.mouseButton.button == sf::Mouse::Left){
                    sf::Vector2f mouse = renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow));
                    for (int i=0; i<tilesOnMap; i++){
                        sf::FloatRect bounds = tileMap.at(i).clickRect;
                        if (bounds.contains(mouse)){
                            std::cout << "clicked at x: "<< tileMap.at(i).axis << " and y : " << tileMap.at(i).ord<< std::endl;

                        }

                    }
                }
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
        renderWindow.setView(view);
        renderWindow.display();
    }
}

void Game::resizeView() {
    float aspectRatio = float(renderWindow.getSize().x) / float(renderWindow.getSize().y);
    view.setSize(500*aspectRatio, 500);

}

void Game::zoomView(int zoom) {
    renderWindow.clear();

        if (zoom == 1)
            view.zoom(0.9);
        else
            view.zoom(1.05);

        renderWindow.setView(view);
}