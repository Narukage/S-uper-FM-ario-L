#pragma once
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "CollisionManager.h"
#include "Map.h"



class Pacman{
    
private:
    float playerSpeed;
    sf::Vector2f current_pos;
    sf::Vector2f dir_move;
    sf::Vector2f movement;
    sf::Sprite misprite;
    sf::Sprite vida;
    sf::Texture textura;
    sf::Font font;
    sf::Text text;
    sf::Text text2;
    sf::Text mytext;
    sf::Text mytext2;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    sf::SoundBuffer buffer2;
    sf::Sound sound2;
    sf::SoundBuffer buffer3;
    sf::Sound sound3;
        
    int fila;
    int columna;
    int vidas;
    int cont = 0;
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
    int score;
    
    
public:

    void pause(); //stop pacman animation
    void resume(); //resume pacman animation
    void restart(); //reinicia su posicion en el mapa
    void kill();
    bool isAlive();
    void updatePos(int presionado, Map* mapa); //pacman movement
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
    sf::Text getTextVidas(){ return text2; };
    
};
