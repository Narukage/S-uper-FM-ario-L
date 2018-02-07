#include "Pacman.h"

//inicializar variables y aplicar textura en el constructor??
Pacman::Pacman(){
    
    current_pos.x = 150.f;
    current_pos.y = 150.f;
    dir_move.x = 0.f;
    dir_move.y = 0.f;
    playerSpeed = 500.f;
    direction_ = Right; //empieza mirando a la derecha
    paused = false;
    alive = true;

    if(!textura.loadFromFile("/home/fv/Escritorio/Pac-Man_sprite.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }

    misprite.setTexture(textura);
    misprite.setPosition(current_pos);
    misprite.setScale(sf::Vector2f(0.2,0.2));

}

void Pacman::updatePos(int presionado){
    
    dir_move.x=0.f;
    dir_move.y=0.f;
         
    if(presionado==1){
         std::cout<<"A presionado"<<std::endl;
         dir_move.x=-1.f;
         dir_move.y=0.f;
    }
    
    if(presionado==2){
         std::cout<<"D presionado"<<std::endl;
         dir_move.x=1.f;
         dir_move.y=0.f;
    }
    
    if(presionado==3){
         std::cout<<"S presionada"<<std::endl;
         dir_move.x=0.f;
         dir_move.y=1.f;
    }
    
    
    if(presionado==4){
         std::cout<<"W presionado"<<std::endl;
         dir_move.x=0.f;
         dir_move.y=-1.f;
    }
    
}

void Pacman::interpolate(float d_time){
        current_pos.x += dir_move.x * playerSpeed * d_time;
        current_pos.y += dir_move.y * playerSpeed * d_time;
        misprite.setPosition(current_pos);
}

sf::Sprite Pacman::getSprite(){
    return misprite;
}




