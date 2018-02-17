#include "Ghost.h"

Ghost::Ghost(){
    movement.x = 0.f;
    movement.y = 0.f;
    paused = false;
    alive = true;
    fila = 1;
    columna = 1;
    
    if(!textura.loadFromFile("/home/naru/Escritorio/ghostrojo.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }

    misprite.setTexture(textura);
    misprite.setPosition(300,300);
    misprite.setScale(sf::Vector2f(/*50.f/217.f,50.f/232.f*/0.3,0.3));
}
//aqui va la IA de los fantasmas
void Ghost::updatePos(){
    
}

/*Ghost::getCurrentPosition(){
    
}*/

sf::Sprite Ghost::getSprite(){
    return misprite;
}

/*Ghost::isAlive(){
    
}

Ghost::kill(){
    
}

Ghost::pause(){
    
}

Ghost::restart(){
    
}

Ghost::resume(){
    
}

Ghost::~Ghost(){
    
}*/