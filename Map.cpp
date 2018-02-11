#include "Map.h"

Map::Map(){
    //rellenar mapa
    cocos = 16;

}

int Map::getWidth(){
    return WIDTH;
}

int Map::getHeight(){
    return HEIGHT;
}

Map Map::getMap(){
    return this;
}

int Map::getTotalCocos(){
    return cocos;
}

