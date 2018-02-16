#include "Map.h"

Map::Map(){

    cocos = 16;
    //reservar memoria para la matriz mapa
    /*for(int i=0;i<SIZE;i++){
        mapa[i] = new int [SIZE];
    }*/    
   
}


void Map::printMap(sf::RenderWindow& window){
    if(!textura.loadFromFile("/home/naru/Escritorio/150px-SokobanWallDepictionDrawing.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    
    
    for(int i=0;i<11;i++){
        for(int j=0;j<SIZE;j++){
            if(map[i][j]==1){ //pared
                sprite.setTexture(textura);
                sprite.setPosition((i*50)+50,(j*50));
                sprite.setScale(sf::Vector2f(0.3,0.3/*50.f/150.f,50.f/150.f*/));
                window.draw(sprite);
            }
            
            if(map[i][j]==2){ //coco
                coco.setFillColor(sf::Color::White);
                coco.setRadius(6);
                coco.setOrigin(-15,-15);
                coco.setPosition((i*50)+50,(j*50));
                window.draw(coco);
            }
        }
    }
}

bool Map::ocupada(int posx, int posy){
    /*int mx = posx/50;
    int my = posy/50;*/
    
    std::cout << "posx = " << posx << "\n";
    std::cout << "posy = " << posy << "\n";
    
    /*std::cout << "mx = " << mx << "\n";
    std::cout << "my = " << my << "\n";*/
    
   if (map[posx][posy]==1){
        return true;
    }else{
       return false;
    }
}

bool Map::hayCoco(int posx, int posy){
    if(map[posx][posy]==2){
        cocos--;
        map[posx][posy]=0;
        std::cout << "cocos: " << cocos << "\n";
        return true;
    }else{
        return false;
    }
}

Map::~Map(){
   //delete [] map;
}

const sf::Sprite &Map::getSprite() const{
    return sprite;
}

