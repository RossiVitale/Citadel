#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.h"
#include "Tile.h"


Game::Game() {
    renderWindow.create(sf::VideoMode(2048, 1536), "Citadel", sf::Style::Default);
    renderWindow.setFramerateLimit(60);
    view.setCenter(1000, 532);
    view.setSize(500, 500);
    renderWindow.clear();
    bool navigating = false;

    Map map("maps/map1.txt");

    sf::Event event{};

    while (renderWindow.isOpen()) {
        while (renderWindow.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed)  //chiudere finestra
                renderWindow.close();
            if (event.type == sf::Event::EventType::Resized)  //resize
                resizeView();
            if (event.type == sf::Event::MouseWheelMoved)   //zoom
                zoomView(event.mouseWheel.delta);
            if (event.type == sf::Event::MouseButtonPressed)  //navigation
                if (event.mouseButton.button == sf::Mouse::Right) {
                    navigating = true;
                    oldPos = renderWindow.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                }
            if (event.type == sf::Event::MouseButtonReleased)
                if (event.mouseButton.button == sf::Mouse::Right)
                    navigating = false;
            if (event.type == sf::Event::MouseMoved) {
                if (navigating) {  //se non si sta premendo il tasto destro del mouse ignora il movimento
                    const sf::Vector2f newPos = renderWindow.mapPixelToCoords(
                            sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
                    const sf::Vector2f deltaPos = oldPos - newPos;
                    view.setCenter(view.getCenter() + deltaPos);
                    renderWindow.clear();
                    renderWindow.setView(view);
                    oldPos = renderWindow.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
                }
            }
            if (event.type == sf::Event::MouseButtonPressed)   //interagire con tile
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mouse = renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow));
                    for (int i = 0; i < tilesOnMap; i++) {
                        sf::FloatRect bounds = map.getTileMapRef(i).getClickRect();
                        if (bounds.contains(mouse)) {
                            std::cout << "clicked at x: " << map.getTileMapRef(i).getCoords("axis") << " and y : "
                                      << map.getTileMapRef(i).getCoords("ord") << std::endl;
                        }
                    }
                }
        }


        if (clock.getElapsedTime().asSeconds() > 0.5f) {
            animateWorld(map);
        }

        for (int i = 0; i < tilesOnMap; i++) {
            renderWindow.draw(map.getTileMapRef(i).getSprite());
        }
        renderWindow.setView(view);
        renderWindow.display();
    }
}

void Game::resizeView() {
    float aspectRatio = float(renderWindow.getSize().x) / float(renderWindow.getSize().y);
    view.setSize(500 * aspectRatio, 500);

}

void Game::zoomView(int zoom) {
    renderWindow.clear();

    if (zoom == 1)
        view.zoom(0.9);
    else
        view.zoom(1.05);

    renderWindow.setView(view);
}

void Game::animateWorld(Map &map) {
    for (int i = 0; i < tilesOnMap; i++) {
        if (map.getTileMapRef(i).getIntRect().left == 72 * 5)
            map.getTileMapRef(i).getIntRect().left = 0;
        else
            map.getTileMapRef(i).getIntRect().left += 72;
        map.getTileMapRef(i).getSprite().setTextureRect(map.getTileMapRef(i).getIntRect());

    }
    clock.restart();
}