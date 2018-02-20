#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Map.h"

class Ghost{
private:
    bool alive;
    float playerSpeed;
    sf::Vector2f movement;
    sf::Sprite misprite;
    sf::Texture textura;
    sf::Vector2f anterior;
    bool choque = false;
    bool paused;
    int fila;
    int columna;
    int cont = 0;
    
public:
    Ghost();
    ~Ghost();
    void pause(); //stop ghost animation
    void resume(); //resume ghost animation
    void restart(); //reinicia su posicion en el mapa
    void kill();
    bool isAlive();
    void updatePos(Map* mapa); //ghost movement
    //void interpolate(float d_time);    //ghost render interpolation
    sf::Vector2f getCurrentPosition();
    sf::Sprite getSprite();
};

