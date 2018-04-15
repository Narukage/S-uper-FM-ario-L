#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Pacman.h"
#include "Ghost.h"
#include "Map.h"
#include "Animation.h"



class Game{
    
private:
    sf::RenderWindow window;
    sf::Event evento;
    sf::Sprite mensaje;
    sf::Sprite ready;
    sf::Sprite morir;
    sf::Texture texturagameover;
    sf::Texture texturavacio;
    sf::Texture texturaready;
    sf::Vector2u textureSize2;
    sf::Texture texturamorir;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    sf::Sound sound2;
    sf::SoundBuffer buffer2;
    sf::Sound sound3;
    sf::SoundBuffer buffer3;
    int contready=0;
    int color; //1 - rosa //2 - azul
    
    
    float deltaTime = 0.0f;
    sf::Clock clock;
    sf::Clock clock2;
    float control;
    
    Pacman *pacman;
    Animation* animation;
    Map *mapa;
    CollisionManager* collision;
    //StateManager* state;
    Ghost *fantasma1;
    Ghost *fantasma2;
    Ghost *fantasma3;
    //Ghost *fantasma3;
    
    bool isPlay = true;
    float cont = 0;
    bool dead=false;
    
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