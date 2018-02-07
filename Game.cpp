#include "Game.h"

Game::Game(): window(sf::VideoMode(800,600),"Ventana de SFML"){
    
}

Game::~Game(){
    delete pacman;
}

void Game::inicializar(){
    
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    pacman = new Pacman();
    //crear mapa
    //crear fantasmas
    //crear objetos
    //asignar posiciones
    
}

void Game::eventos(){
    
    while(window.pollEvent(evento)){
    
        switch(evento.type){

                    case sf::Event::Closed:
                        isPlay = false;

                    case sf::Event::KeyPressed:
                        if(evento.key.code==sf::Keyboard::A){
                            presionado = A;
                        }else

                        if(evento.key.code==sf::Keyboard::D){
                            presionado = D;
                        }else

                        if(evento.key.code==sf::Keyboard::S){
                            presionado = S;
                        }else
                        
                        if(evento.key.code==sf::Keyboard::W){
                            presionado = W;
                        }
                }
    }
}

void Game::update(){
    
    pacman->updatePos(presionado);  //Actualizamos posición personaje
    presionado = none;                              //Estado de movimiento = 0
}

void Game::render(float d_time){
    
    window.clear(sf::Color::Black);
    pacman->interpolate(d_time);
    window.draw(pacman->getSprite());
    window.display();
}

void Game::cleared(){
 
    window.close();
}

void Game::run(){
    
    inicializar();
    float s = 0.f;
    while(isPlay){
        if(s >= 1.f/15.f){
            eventos();
            update();
            s = 0.f;
        }
        
        render(1.f/120.f);
        
        s+=1.f/120.f;
    }
    cleared();
}