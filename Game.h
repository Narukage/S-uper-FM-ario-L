#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Pacman.h"
#include "Ghost.h"
#include "Map.h"



class Game{
    
private:
    sf::RenderWindow window;
    sf::Event evento;      
    sf::SoundBuffer buffer;
    sf::Sound sound;
    //sf::Music music;
    int cont2 = 0;
    
    
    Pacman *pacman;
    Map *mapa;
    CollisionManager* collision;
    //StateManager* state;
    Ghost *fantasma1;
    Ghost *fantasma2;
    Ghost *fantasma3;
    
    bool isPlay = true;
    float cont = 0;
    
    enum Presionado{
        none = 0,
        A = 1,
        D = 2,
        S = 3,
        W = 4
    };
    
    Presionado presionado;
   
private:
    void inicializar();
    void eventos();
    void update();
    void render(float d_time);
    void cleared();
    
public:
    Game();
    ~Game();
    void run();
};