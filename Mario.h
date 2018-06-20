#ifndef MARIO_H
#define MARIO_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Mario {
    
public:
    Mario();
    virtual ~Mario();
    
    move();
    jump();
    increaseCoins()           { coins++;      };
    
    setAlive(bool b)          { alive = b;    };
    setLifes(int l)           { lifes = l;       };
    setOnGround(bool g)       { onGround = g; };
    
private:
    
    int lifes, coins, points;
    float dx, dy; // velocity components
    bool onGround, alive;
    sf::Sprite sprite;
};

#endif

