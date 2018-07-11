#include "Enemy.h"

Enemy::Enemy() {
    direction = 1;
    alive = true;
    velocityX = 0.0;
    cont = 0;
    direction = -1;
    x = 500;
    
    id = AnimationManager::Instance(1)->crearAnimacion("assets/sprites/goombarun.png",8,1,0.01f,8,1);
    
    if(!textura.loadFromFile("assets/sprites/enemy.png")){
        std::cout << "Error al cargar la textura." << std::endl;
        exit(-1);
    }
    
    sprite.setTexture(textura);
    sprite.setScale(0.1,0.1);
}

void Enemy::move(){
    
    if(cont == 70){
        direction = -direction;
        cont = 0;
    }
    
    if(direction == -1){ //izq
        velocityX = -2.5;
        AnimationManager::Instance(1)->updateAnimacion(id, 0, 0.02f);
    }
    
    if(direction == 1){ //dcha
        velocityX = 2.5;
        AnimationManager::Instance(1)->updateAnimacion(id, 0, 0.02f);
    }

    
    sprite.setPosition(x, 220);

    velocityX += accelerationX;

    x += velocityX;
       
    cont++;
        
}

void Enemy::draw(sf::RenderWindow &window){
    AnimationManager::Instance(1)->dibujarAnimacion(id,x,220,1,window);
}

void Enemy::kill(){
    alive = false;
}

Enemy::~Enemy() {
    
}

