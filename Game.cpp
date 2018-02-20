#include "Game.h"


Game::Game(): window(sf::VideoMode(800,600),"Ventana de SFML"){
   
}

Game::~Game(){
    delete pacman;
    delete mapa;
    delete collision;
    //delete fantasma1;
}

void Game::inicializar(){
    
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    //crear pacman
    pacman = new Pacman();
    //crear mapa
    mapa = new Map();
    collision = new CollisionManager();
    //crear fantasmas
    fantasma1 = new Ghost();
    /*fantasma2 = new Ghost();
    fantasma3 = new Ghost();*/
    //crear objetos
    //asignar posiciones
    
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
                        
                        if(evento.key.code==sf::Keyboard::W){
                            presionado = W;
                        }else
                        
                        if(evento.key.code==sf::Keyboard::Q){
                            isPlay = false;
                        }
                }
    }
}

void Game::update(){
    
    pacman->updatePos(presionado, mapa);  //Actualizamos posición personaje
    presionado = none;                              //Estado de movimiento = 0
    if(cont==3){ //preguntar por que core dumped por hacer un contador
        fantasma1->updatePos(mapa);
        cont = 0;
    }
    cont ++;
    if(collision->checkSpriteCollision(pacman->getSprite(),fantasma1->getSprite())&&pacman->isAlive()){
        pacman->kill();
        std::cout << "Te han matao" << "\n";
    }
}

void Game::render(float d_time){
    
    window.clear(sf::Color::Black);
    sf::Vector2f current_pos = pacman->getCurrentPosition();
    //pacman->interpolate(d_time, mapa);
    window.draw(pacman->getSprite());
    window.draw(pacman->getText());
    window.draw(pacman->getTextVidas());
    window.draw(pacman->getPuntos());
    window.draw(pacman->getVidas());
    //dibujar mapa
    mapa->printMap(window);
    //dibujar fantasmas
    window.draw(fantasma1->getSprite());
    
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