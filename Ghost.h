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
    sf::Texture textura;
    sf::Texture texturaghost;
    sf::Texture texturacaza;
    sf::Vector2f anterior;
    sf::Vector2u textureSize;
    sf::Vector2u textureSize2;
    Animation* animation;
    Animation* animation2;
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
    void kill(int color);
    bool isAlive();
    int getFila(){ return fila;};
    int getColumna(){ return columna;};
    int getColor(){ return color; }
    void updatePos(Map* mapa, float deltaTime, bool estadocaza); //ghost movement
    //void interpolate(float d_time);    //ghost render interpolation
    sf::Vector2f getCurrentPosition();
    sf::Sprite getSprite();
};

