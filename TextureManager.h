#ifndef CITADELL_TEXTUREMANAGER_H
#define CITADELL_TEXTUREMANAGER_H

#include <iostream>
#include "SFML/Graphics.hpp"


class TextureManager {
private:

    std::map<std::string, sf::Texture> textures;   //conservare tutte le texture

public:

    void loadTexture(const std::string &name, const std::string &filename);   //nome con cui conservare e path

    sf::Texture &getRefTex(
            const std::string &name);   //restituisce un riferimento alla texture il cui nome viene passato alla funzione

    TextureManager();
};

#endif