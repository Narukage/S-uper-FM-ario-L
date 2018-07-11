#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Mario.h"
#include "Enemy.h"
#include "Map.h"
#include "Camera.h"
#include "CollisionManager.h"

using namespace std;

class Game{
    
private:
    sf::RenderWindow window;
    sf::Event evento;  
    sf::Clock clock;
    
    
    bool isPlay     = true;
    bool pressed    = false;
    bool space      = false;
    float cont      = 0;
    
    char presionado;
    Mario* mario; 
    Enemy* enemy;
    Map* map;
    Camera* camera;
    CollisionManager* collision;
    
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