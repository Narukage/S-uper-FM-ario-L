#ifndef MARIO_H
#define MARIO_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "IFachada.h"
#include "AnimationManager.h"
#include "Map.h"
#include "CollisionManager.h"
#include "Mario.h"

using namespace std;

class Mario {
    
public:
    Mario();
    virtual ~Mario();
    
    void move(char presionado, bool space, Map &map, CollisionManager &collision, Mario &mario);
    void draw(sf::RenderWindow &window);
    void increaseCoins()           { coins++;           };
    void increasePoints()          { points++;          };
    
    void setAlive(bool b)          { alive = b;         };
    void setLifes()                { lifes--;           };
    void setOnGround(bool g)       { onGround = g;      };
    void setDirection(int d)       { direction = d;     };
    
    sf::Sprite getSprite()         { return sprite;     };
    float getX()                   { return x;          };
    float getY()                   { return y;          };
    bool getOnGround()             { return onGround;   };
    int getLifes()                 { return lifes;      };
    int getScore()                 { return points;     };
    int getCoins()                 { return coins;      };
    
    void setX(float n)             { x = n;             };
    void setY(float n)             { x = n;             };
    void setVelocityX(float n)     { velocityX = n;     };
    void setVelocityY(float n)     { velocityY = n;     };
    
private:
    
    int lifes, coins, points, direction, gravity, id;
    float dx, dy, acx, acy, maxspeed; // velocity components
    
    float x                 = 0;
    float y                 = 0;
    float velocityX         = 0;
    float velocityY         = 0;
    float accelerationX     = 0;
    float accelerationY     = 0;
    
    IFachada* motor;
    
    bool onGround, alive, falling, up;
    
    sf::Sprite sprite;
    sf::Texture textura;
    
    sf::Sprite sprite2;
    sf::Texture textura2;
    
};

#endif

