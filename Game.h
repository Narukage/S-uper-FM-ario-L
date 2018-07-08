#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Mario.h"

using namespace std;

class Game{
    
private:
    sf::RenderWindow window;
    sf::Event evento;      
    
    bool isPlay     = true;
    bool pressed    = false;
    float cont      = 0;
    
    char presionado;
    Mario* mario; 
    
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