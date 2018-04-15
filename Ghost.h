#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Animation.h"

class Ghost{
private:
    bool alive;
    float playerSpeed;
    sf::Vector2f movement;
    sf::Sprite misprite;
    sf::Sprite misprite2;
    sf::Texture textura;
    sf::Texture texturaghost;
    sf::Vector2f anterior;
    sf::Vector2u textureSize;
    Animation* animation;
    bool choque = false;
    bool paused;
    int fila;
    int columna;
    int cont = 0;
    int color;
    
public:
    Ghost(int color);
    ~Ghost();
    void pause(); //stop ghost animation
    void resume(); //resume ghost animation
    void restart(); //reinicia su posicion en el mapa
    void kill();
    bool isAlive();
    void updatePos(Map* mapa, float deltaTime); //ghost movement
    //void interpolate(float d_time);    //ghost render interpolation
    sf::Vector2f getCurrentPosition();
    sf::Sprite getSprite();
};

