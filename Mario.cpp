#include "Mario.h"

Mario::Mario() {
    lifes       = 3;
    coins       = 0;
    points      = 0;
    onGround    = true;
    alive       = true;
    dx          = 0;
    dy          = 0;
    ac          = 0;
    maxspeed    = 50;
    
    if(!textura.loadFromFile("assets/sprites/mario.png")){
        std::cout << "Error al cargar la textura." << std::endl;
        exit(-1);
    }
    
    sprite.setTexture(textura);
    sprite.setPosition(300,300);
    sprite.setScale(0.2,0.2);

}

Mario::~Mario() {
    
}

void Mario::move(char presionado){
    dx = 0;
    dy = 0;
    
    if(presionado == 'A'){ //izq
        ac = -15;
    }
    
    if(presionado == 'D'){ //dcha
        ac = 15;
    }
    
    if(presionado == 'Space'){ //saltar
        jump();
    }
    
    if(presionado == 'S'){ //agacharse
        
    }
    
    dx += ac;
    
    if(dx > maxspeed){
        dx = maxspeed;
    }
    
    if(dx < -maxspeed){
        dx = -maxspeed;
    }
    
    sprite.move(dx, dy);
        
}

void Mario::jump(){
    dy += ac;
    
    onGround = false;
}

