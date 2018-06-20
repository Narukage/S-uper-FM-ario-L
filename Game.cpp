#include "Game.h"


Game::Game(): window(sf::VideoMode(800,600),"Ventana de SFML"){
   
}

Game::~Game(){
    
}

void Game::inicializar(){
    
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    //crear a mario
    
}

void Game::eventos(){
    
    while(window.pollEvent(evento)){
    
        switch(evento.type){

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
                        
                        if(evento.key.code==sf::Keyboard::Space){
                            presionado = Space;
                        }else
                        
                        if(evento.key.code==sf::Keyboard::Q){
                            isPlay = false;
                        }
                }
    }
}

void Game::update(){
    
}

void Game::render(float d_time){
    
    window.clear(sf::Color::Black);  
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