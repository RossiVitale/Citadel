#include "TextureManager.h"

TextureManager::TextureManager(TileType type) {

    switch (type) {
        case Plain :
            this->TextureAtlas.reserve(1);
            this->texture.loadFromFile("media/Plain.png");
            this->TextureAtlas.push_back(texture);
            break;

        case Forest:
            this->TextureAtlas.reserve(1);
            this->texture.loadFromFile("media/Forest.png");
            this->TextureAtlas.push_back(texture);
            break;

        case Water:
            this->TextureAtlas.reserve(1);
            this->texture.loadFromFile("media/Water.png");
            this->TextureAtlas.push_back(texture);
            break;

        case Cityhall:
            this->TextureAtlas.reserve(1);
            this->texture.loadFromFile("media/Cityhall.png");
            this->TextureAtlas.push_back(texture);
            break;

        case Residential:
            this->TextureAtlas.reserve(3);
            this->texture.loadFromFile("media/Residential1.png");  //size 4
            this->TextureAtlas.push_back(texture);
            this->texture.loadFromFile("media/Residential2.png");   //size 4
            this->TextureAtlas.push_back(texture);
            this->texture.loadFromFile("media/Residential3.png");    //size 5
            this->TextureAtlas.push_back(texture);
            break;

        case Farm:
            this->TextureAtlas.reserve(3);
            this->texture.loadFromFile("media/Farm1.png");   //size 3
            this->TextureAtlas.push_back(texture);
            this->texture.loadFromFile("media/Farm2.png");    //size 6
            this->TextureAtlas.push_back(texture);
            this->texture.loadFromFile("media/Farm3.png");    //size 3
            this->TextureAtlas.push_back(texture);
            break;

        case Park:
            this->TextureAtlas.reserve(1);
            this->texture.loadFromFile("media/Park.png");
            this->TextureAtlas.push_back(texture);
            break;

        case Commercial:
            this->TextureAtlas.reserve(3);
            this->texture.loadFromFile("media/Commercial1.png");  //size 8
            this->TextureAtlas.push_back(texture);
            this->texture.loadFromFile("media/Commercial2.png");   //size 8
            this->TextureAtlas.push_back(texture);
            this->texture.loadFromFile("media/Commercial3.png");   //size 8
            this->TextureAtlas.push_back(texture);
            break;

        case IndEnergy:
            this->TextureAtlas.reserve(3);
            this->texture.loadFromFile("media/IndEnergy1.png");  //size 5
            this->TextureAtlas.push_back(texture);
            this->texture.loadFromFile("media/IndEnergy2.png");  //size 5
            this->TextureAtlas.push_back(texture);
            this->texture.loadFromFile("media/IndEnergy3.png");   //size 5
            this->TextureAtlas.push_back(texture);
            break;


        case CleanEnergy:
            this->TextureAtlas.reserve(3);
            this->texture.loadFromFile("media/CleanEnergy1.png");  //size 1
            this->TextureAtlas.push_back(texture);
            this->texture.loadFromFile("media/CleanEnergy2.png");  //size 3
            this->TextureAtlas.push_back(texture);
            this->texture.loadFromFile("media/CleanEnergy3.png");  //size 3
            this->TextureAtlas.push_back(texture);
            break;

        case WorkingZone:
            this->TextureAtlas.reserve(3);
            this->texture.loadFromFile("media/Work1.png");   //size 5
            this->TextureAtlas.push_back(texture);
            this->texture.loadFromFile("media/Work2.png");   //size 5
            this->TextureAtlas.push_back(texture);
            this->texture.loadFromFile("media/Work3.png");   //size 5
            this->TextureAtlas.push_back(texture);
            break;

        case Decoration:
            this->TextureAtlas.reserve(1);
            this->texture.loadFromFile("media/Decoration.png");
            this->TextureAtlas.push_back(texture);
            break;

        case EventZone:
            this->TextureAtlas.reserve(2);
            this->texture.loadFromFile("media/EventStatic.png");  //size 1
            this->TextureAtlas.push_back(texture);
            this->texture.loadFromFile("media/EventAnim.png");   //size 4
            this->TextureAtlas.push_back(texture);
            break;

    }

}