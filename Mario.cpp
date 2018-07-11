#include "Mario.h"
#include "AnimationManager.h"

Mario::Mario() {
    lifes         = 3;
    coins         = 0;
    points        = 0;
    onGround      = true;
    alive         = true;
    gravity       = 1.9;
    maxspeed      = 50;
    x             = 200;
    y             = 220;
    up            = false;
    accelerationY = gravity;
    
    
    id = AnimationManager::Instance(1)->crearAnimacion("assets/sprites/mariorun.png",5,1,0.1f,5,1);
    
    if(!textura.loadFromFile("assets/sprites/mariojump.png")){
        std::cout << "Error al cargar la textura." << std::endl;
        exit(-1);
    }
    
    sprite.setTexture(textura);
    sprite.setScale(1,1);
    AnimationManager::Instance(1)->updateAnimacion(id, 0, 0.02f);

}

Mario::~Mario() {
    
}

void Mario::move(char presionado, bool space, Map &map, CollisionManager &collision, Mario &mario){
    
    if(presionado == 'A'){ //izq
        velocityX = -1.5;
        AnimationManager::Instance(1)->updateAnimacion(id, 0, 0.02f);
    }
    
    if(presionado == 'D'){ //dcha
        velocityX = 1.5;
        AnimationManager::Instance(1)->updateAnimacion(id, 0, 0.02f);
    }
    
    if(space){
        if(onGround){
            if(presionado == 'P'){ //saltar
                velocityY = -20;
                velocityX = 1.5;
                onGround = false;
            }
        }
    }
    
    if(presionado == 'S'){ //agacharse
        
    }
    
   
    float aux_x = x;
    float aux_y = y;
    
    velocityX += accelerationX;
    velocityY += accelerationY;
   
    x += velocityX;
    y += velocityY;
    
    

    /*if(y < 140){                  //If you are above ground
       velocityY += gravity;
    }*/
    
    //Colision en X
    sprite.setPosition(x, aux_y);
    
    if(collision.checkSpriteCollision(sprite, map.getSprite()) || collision.checkSpriteCollision(sprite, map.getSprite2()) || collision.checkSpriteCollision(map.getTubo(), sprite) || collision.checkSpriteCollision(sprite, map.getSprite3()) ||
            collision.checkSpriteCollision(sprite, map.getCaja()) || collision.checkSpriteCollision(sprite, map.getCaja2())){
         x = aux_x;
    }
    
    //Colision en Y
    sprite.setPosition(aux_x, y);
    if(collision.checkSpriteCollision(sprite, map.getTubo()) || collision.checkSpriteCollision(sprite, map.getCaja()) || collision.checkSpriteCollision(sprite, map.getCaja2())){
        y = aux_y;
    }
    
    if(collision.checkSpriteCollision(sprite, map.getSprite()) || collision.checkSpriteCollision(sprite, map.getSprite2()) || collision.checkSpriteCollision(sprite, map.getSprite3()))
    {
        mario.increasePoints();
        y = aux_y;
        velocityY = 0;
    }
    
    
    /*int _width = map.getWidth();
    int _height = map.getHeight();
    
    sf::Sprite**** _tilemapSprite =  map.getTileMap();
    
    for(int y=0; y<_height; y++){
            for(int x=0; x<_width; x++){
                if(_tilemapSprite[1][y][x]!=NULL){
                   //Colision en X
                    sprite.setPosition(x, aux_y);

                    if(collision.checkSpriteCollision(sprite, *(_tilemapSprite[1][y][x]))){
                         x = aux_x;
                    }

                    //Colision en Y
                    sprite.setPosition(aux_x, y);
                    if(collision.checkSpriteCollision(*(_tilemapSprite[1][y][x]), sprite)){
                        y = aux_y;
                    }

                    if(collision.checkSpriteCollision(sprite, *(_tilemapSprite[1][y][x])))
                    {
                        mario.increasePoints();
                        y = aux_y;
                        velocityY = 0;
                    }
                }
            }
        }*/
    
    //Avoid above ground movement
    if(y > 220)
        y = 220;
    
    if(y == 220)
        onGround = true;
                    
    sprite.setPosition(x, y);

    
}

void Mario::draw(sf::RenderWindow &window){
    if(onGround){
        AnimationManager::Instance(1)->dibujarAnimacion(id,x,y,1,window);
    }else{
        window.draw(sprite);
    }
}

