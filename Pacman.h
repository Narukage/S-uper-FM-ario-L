#pragma once
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "CollisionManager.h"
#include "Map.h"
#include "Animation.h"



class Pacman{
    
private:
    float playerSpeed;
    sf::Vector2f current_pos;
    sf::Vector2f dir_move;
    sf::Vector2f movement;
    sf::Sprite misprite;
    sf::Sprite player;
    sf::Sprite vida;
    sf::Vector2u textureSize;
    
    sf::Vector2u textureSize3;
    sf::Texture textura;
    
    sf::Texture texturaanimacion;
    sf::Font font;
    sf::Text text;
    sf::Text text2;
    sf::Text mytext;
    sf::Text mytext2;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    sf::SoundBuffer buffer3;
    sf::Sound sound3;
    sf::SoundBuffer buffer4;
    sf::Sound sound4;
    sf::Texture texturapacman;
    
    sf::Clock clock;
    
    Animation* animation;
    Animation* animation2;
        
    int fila;
    int columna;
    int vidas;
    int cont = 0;
    float control;
    bool estadocaza=false;
    //Estado estado;
    
    enum Estado{
        Victoria = 1,
        Derrota = 0
    };
    
    enum Direction{
        Left = -1,
        Right = 1,
        Up = 2,
        Down = -2,
        None = 0
    };
    
    Direction direction_;
    bool paused;
    bool alive;
    bool win = false;
    int score;
    
    
public:

    void pause(); //stop pacman animation
    void resume(); //resume pacman animation
    void restart(); //reinicia su posicion en el mapa
    void kill();
    bool isAlive();
    bool getEstadoCaza(){ return estadocaza; };
    void setEstadoCaza(bool estado);
    void updatePos(int presionado, Map* mapa, float deltaTime); //pacman movement
    void interpolate(float d_time, Map* mapa);    //pacman render interpolation
    float getVelocity();
    sf::Vector2f getCurrentPosition();
    void setDirection(Pacman::Direction direction); //cambiar direccion en la que mira
    sf::Sprite getSprite();
    Pacman();
    ~Pacman();
    int getScore();
    const sf::Sprite &getSprite() const;
    sf::Text getText(){ return text; };
    sf::Text getPuntos();
    sf::Sprite getVidas();
    int getVidass() { return vidas; };
    sf::Text getTextVidas(){ return text2; };
    bool getWin(){return win; };
    
};
