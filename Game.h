#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>



class Game{
    
private:
    sf::RenderWindow window;
    sf::Event evento;      
    
    bool isPlay = true;
    float cont = 0;
    
    enum Presionado{
        none = 0,
        A = 1,
        D = 2,
        S = 3,
        Space = 4
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