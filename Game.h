
#ifndef GAME_H
#define GAME_H
#endif /* GAME_H */
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Pacman.h"


class Game{
    
private:
    sf::RenderWindow window;
    sf::Event evento;
    
    Pacman *pacman;
    
    bool isPlay = true;
    
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