#include "Tile.h"


Terrain::Terrain(TileType type, float axis, float ord) {
    this->axis =axis;
    this->ord=ord;
    this->type=type;
    this->clickRect={this->axis+18, this->ord+9, 36,18};


    switch (type) {

        case Plain: {
            type=Plain;
            this->tex = new TextureManager(Plain);
            this->allowConstruction = true;
            this->tileLevel = 1;
            this->maxLevel = 1;
            break;
        }


        case Forest: {
            type= Forest;
            this->tex = new TextureManager(Forest);
            this->allowConstruction = false;
            this->tileLevel = 1;
            this->maxLevel = 1;
            break;
        }


        case Water: {
            type=Water;
            this->tex = new TextureManager(Water);
            this->allowConstruction = false;
            this->tileLevel = 1;
            this->maxLevel = 1;
            break;
        }

        default :{
            std::cout<< "error: not a terrain"<< std::endl;
            break;
        }
    }
    this->sprite.setPosition(this->axis, this->ord);
    this->texture=tex->TextureAtlas.at(0);
    sprite.setTexture(texture);
    sprite.setTextureRect(intRect);

}



////////////////////////////////////////////////////////////////////////////////////////////


Building::Building(TileType type, int tileLevel,float axis, float ord) {
    this->axis =axis;
    this->ord=ord;
    this->type=type;
    this->clickRect={this->axis+18, this->ord+9, 36,18};

    switch (type){
        case Cityhall:
            type=Cityhall;
            this->tex = new TextureManager(Cityhall);
            this->tileLevel=tileLevel;
            this->maxLevel=1;
            break;


        case Residential:
            type=Residential;
            this->tex = new TextureManager(Residential);
            this->tileLevel=tileLevel;
            this->maxLevel=3;
            break;


        case Farm:
            type=Farm;
            this->tex = new TextureManager(Farm);
            this->maxLevel=3;
            this->tileLevel=tileLevel;
            break;


        case Park:
            type=Park;
            this->tex = new TextureManager(Park);
            this->maxLevel=1;
            this->tileLevel=tileLevel;
            break;


        case Commercial:
            type=Commercial;
            this->tex = new TextureManager(Commercial);
            this->maxLevel=3;
            this->tileLevel=tileLevel;
            break;


        case WorkingZone:
            type=WorkingZone;
            this->tex = new TextureManager(WorkingZone);
            this->maxLevel=3;
            this->tileLevel=tileLevel;
            break;


        case CleanEnergy:
            type=CleanEnergy;
            this->tex = new TextureManager(CleanEnergy);
            this->maxLevel=3;
            this->tileLevel=tileLevel;
            break;



        case IndEnergy:
            type=IndEnergy;
            this->tex = new TextureManager(IndEnergy);
            this->maxLevel=3;
            this->tileLevel=tileLevel;
            break;


        case EventZone:   //livello 1: static        livello 2: dinamic
            type=EventZone;
            this->tex = new TextureManager(EventZone);
            this->maxLevel=2;
            this->tileLevel=tileLevel;
            break;



        case Decoration:
            type=Decoration;
            this->tex = new TextureManager(Decoration);
            break;

        default :
            std::cout<< "error: not a terrain"<< std::endl;
            break;


    }
    this->sprite.setPosition(this->axis, this->ord);
    this->texture=tex->TextureAtlas.at(this->tileLevel-1);
    sprite.setTexture(texture);
    sprite.setTextureRect(intRect);
}
