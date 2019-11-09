#include "TextureManager.h"


TextureManager::TextureManager() {
    loadTexture("Plain", "media/Plain.png");
    loadTexture("Water", "media/Water.png");
    loadTexture("Forest", "media/Forest.png");
    loadTexture("Cityhall", "media/Cityhall.png");
    loadTexture("CleanEnergy1", "media/CleanEnergy1.png");
    loadTexture("CleanEnergy2", "media/CleanEnergy2.png");
    loadTexture("CleanEnergy3", "media/CleanEnergy3.png");
    loadTexture("IndEnergy1", "media/IndEnergy1.png");
    loadTexture("IndEnergy2", "media/IndEnergy2.png");
    loadTexture("IndEnergy3", "media/IndEnergy3.png");
    loadTexture("Commercial1", "media/Commercial1.png");
    loadTexture("Commercial2", "media/Commercial2.png");
    loadTexture("Commercial3", "media/Commercial3.png");
    loadTexture("Decoration", "media/Decoration.png");
    loadTexture("EventStatic", "media/EventStatic.png");
    loadTexture("EventAnim", "media/EventAnim.png");
    loadTexture("Farm1", "media/Farm1.png");
    loadTexture("Farm2", "media/Farm2.png");
    loadTexture("Farm3", "media/Farm3.png");
    loadTexture("Park", "media/Park.png");
    loadTexture("Residential1", "media/Residential1.png");
    loadTexture("Residential2", "media/Residential2.png");
    loadTexture("Residential3", "media/Residential3.png");
    loadTexture("Work1", "media/Work1.png");
    loadTexture("Work2", "media/Work2.png");
    loadTexture("Work3", "media/Work3.png");
}

void TextureManager::loadTexture(const std::string &name, const std::string &filename) {
    sf::Texture tex;
    tex.loadFromFile(filename);

    this->textures[name] = tex;
}

sf::Texture &TextureManager::getRefTex(const std::string &name) {
    return this->textures.at(name);
}