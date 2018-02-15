#include "Map.h"

Map::Map(){

    cocos = 16;
    //reservar memoria para la matriz mapa
    for(int i=0;i<SIZE;i++){
        mapa[i] = new int [SIZE];
    }
    //crear algunas paredes
    for(int i=0;i<SIZE;i++){
       for(int j=0;j<SIZE;j++){
           if(i==0 || i==SIZE-1){
               mapa[i][j] = 1;
           }
           if(j==0 || j==SIZE-1){
               mapa[i][j] = 1;
           }
       }
    }
    
    
   
}


void Map::printMap(sf::RenderWindow& window){
    if(!textura.loadFromFile("/home/fv/Escritorio/150px-SokobanWallDepictionDrawing.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(mapa[i][j]==1){
                sprite.setTexture(textura);
                sprite.setPosition(i*50,j*50);
                sprite.setScale(sf::Vector2f(0.3,0.3));
                window.draw(sprite);
            }
        }
    }
}

int Map::getWidth(){
    return WIDTH;
}

int Map::getHeight(){
    return HEIGHT;
}

bool Map::ocupada(int posx, int posy){
   if (mapa[posx][posy]==1){
        return true;
    }
}

int Map::getTotalCocos(){
    return cocos;
}

Map::~Map(){
   delete [] mapa;
}

const sf::Sprite &Map::getSprite() const{
    return sprite;
}

