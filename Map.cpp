#include "Map.h"

Map::Map(){

    cocos = 59;
    //reservar memoria para la matriz mapa
    /*for(int i=0;i<SIZE;i++){
        mapa[i] = new int [SIZE];
    }*/
    if(!textura.loadFromFile("assets/cubo.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }    
}


void Map::printMap(sf::RenderWindow& window){
    
    
    
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
            
            if(map[i][j]==3){ //intersecciones
                coco.setFillColor(sf::Color::White);
                coco.setRadius(10);
                coco.setOrigin(-15,-15);
                coco.setPosition((i*50)+50,(j*50));
                window.draw(coco);
            }
        }
    }
}

bool Map::ocupada(int posx, int posy){
    
    /*std::cout << "posx ocupada = " << posx << "\n";
    std::cout << "posy ocupada = " << posy << "\n";*/
    
   if (map[posx][posy]==1){
        return true;
    }else{
       return false;
    }
}

bool Map::intersecta(int posx, int posy){
    
    /*std::cout << "posx = " << posx << "\n";
    std::cout << "posy = " << posy << "\n";
    
    std::cout << "intersect[posx][posy]: " << intersect[posx][posy] << "\n";*/
    
    if (intersect[posx][posy]==1){
        return true;
    }else{
       return false;
    }
}

bool Map::hayCoco(int posx, int posy){
    if(map[posx][posy]==2 || map[posx][posy]==3){
        cocos--;
        map[posx][posy]=0;
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

