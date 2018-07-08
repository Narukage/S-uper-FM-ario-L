#ifndef MARIO_H
#define MARIO_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

class Mario {
    
public:
    Mario();
    virtual ~Mario();
    
    void move(char presionado);
    void jump();
    void increaseCoins()           { coins++;      };
    
    void setAlive(bool b)          { alive = b;    };
    void setLifes(int l)           { lifes = l;    };
    void setOnGround(bool g)       { onGround = g; };
    
    sf::Sprite getSprite()         { return sprite; };
    
private:
    
    int lifes, coins, points;
    float dx, dy, ac, maxspeed; // velocity components
    bool onGround, alive;
    sf::Sprite sprite;
    sf::Texture textura;
    
};

#endif

