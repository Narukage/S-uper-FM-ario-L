#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "AnimationManager.h"
#include "IFachada.h"

using namespace std;

class Enemy {
    
public:
    Enemy();
    virtual ~Enemy();
    
    void move();
    void kill();
    void draw(sf::RenderWindow &window);
    
    sf::Sprite getSprite()  { return sprite; };
    bool getAlive()         { return alive;  };
    
    
private:
    bool alive;
    int direction, id;
    float velocityX, accelerationX, x;
    
    sf::Sprite sprite;
    sf::Texture textura;
    
    int cont;

};

#endif /* ENEMY_H */

