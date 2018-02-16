#include "Pacman.h"

//inicializar variables y aplicar textura en el constructor??
Pacman::Pacman(){
    
    current_pos.x = 250.f;
    current_pos.y = 250.f;
    dir_move.x = 0.f;
    dir_move.y = 0.f;
    playerSpeed = 500.f;
    direction_ = Right; //empieza mirando a la derecha
    paused = false;
    alive = true;
    score = 0;

    if(!textura.loadFromFile("/home/naru/Escritorio/Pac-Man_sprite.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }

    misprite.setTexture(textura);
    misprite.setPosition(current_pos);
    misprite.setScale(sf::Vector2f(50.f/217.f,50.f/232.f));

}

void Pacman::updatePos(int presionado){
    
    dir_move.x=0.f;
    dir_move.y=0.f;
         
    if(presionado==1){
         dir_move.x=-1.f;
         dir_move.y=0.f;
    }
    
    if(presionado==2){
         dir_move.x=1.f;
         dir_move.y=0.f;
    }
    
    if(presionado==3){
         dir_move.x=0.f;
         dir_move.y=1.f;
    }
    
    
    if(presionado==4){
         dir_move.x=0.f;
         dir_move.y=-1.f;
    }
}

void Pacman::interpolate(float d_time, Map* mapa){
    
    //Old position
    sf::Vector2f oldpos = current_pos;
    
    //Calculate new pos
    current_pos.x += dir_move.x * playerSpeed * d_time;
    current_pos.y += dir_move.y * playerSpeed * d_time;
        
    //Antigua pos
    if(!mapa->ocupada(current_pos.x, current_pos.y))
    {
        misprite.setPosition(current_pos);        
    }else{
        //Restore position
        current_pos = oldpos;
    }
    
    misprite.setPosition(current_pos);
    //volver a programar el movimiento original sin interpolacion
    //hacer funcion en mapa para controlar la posicion de pacman en la matriz
    //llamar a la funcion y pasarle 1 o -1 a i o j para cambiar posicion en matriz
}

sf::Sprite Pacman::getSprite(){
    return misprite;
}

float Pacman::getVelocity(){
    return playerSpeed;
}

void Pacman::setDirection(Pacman::Direction direction){
    if(direction!=direction_){
        direction_=direction;
    }
}

void Pacman::pause(){
    
}

void Pacman::restart(){
    
}

void Pacman::resume(){
    
}

void Pacman::kill(){
    
}

bool Pacman::isAlive(){
    if(alive){
        return true;
    }else{
        return false;
    }
}

int Pacman::getScore(){
    return score;
}

sf::Vector2f Pacman::getCurrentPosition(){
    return current_pos;
}

Pacman::~Pacman(){
    
}

const sf::Sprite &Pacman::getSprite() const{
    return misprite;
}




