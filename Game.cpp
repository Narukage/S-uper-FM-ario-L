#include "Game.h"
#include "Enemy.h"
#include "Map.h"


Game::Game(): window(sf::VideoMode(800,600),"Ventana de SFML"){
   
}

Game::~Game(){
    
}

void Game::inicializar(){
    
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    mario = new Mario();
    enemy = new Enemy();
    map = new Map();
    camera = new Camera(window, *mario);
    collision = new CollisionManager();
}

void Game::eventos(){
    
    while(window.pollEvent(evento)){
    
        switch(evento.type){

                    case sf::Event::KeyPressed:
                        if(evento.key.code==sf::Keyboard::A){
                            presionado = 'A';
                            pressed = true;
                        }else

                        if(evento.key.code==sf::Keyboard::D){
                            presionado = 'D';
                            pressed = true;
                        }else

                        if(evento.key.code==sf::Keyboard::S){
                            presionado = 'S';
                            pressed = true;
                        }else
                        
                        if(evento.key.code==sf::Keyboard::Space){
                            presionado = 'P';
                            space = true;
                        }else
                        
                        if(evento.key.code==sf::Keyboard::Q){
                            isPlay = false;
                        }
                }
    }
}

void Game::update(){
    if(pressed){
        mario->move(presionado, space, *map, *collision, *mario);
    }
    if(mario->getLifes() !=0 ){
        space = false;
        enemy->move();
        camera->move(window, *mario);

        //Enemy collision
        if(clock.getElapsedTime().asSeconds()>2.5){
            if(collision->checkSpriteCollision(mario->getSprite(), enemy->getSprite()) || collision->checkSpriteCollision(mario->getSprite(), map->getCascada1())){
                clock.restart();
             if(mario->getOnGround()){
                    mario->setLifes();
                    cout << "vidas: " << mario->getLifes() << endl;
                    mario->setX(10);
                    mario->setVelocityX(0);
                    mario->setVelocityY(0);
                    camera->getCamara().setCenter(200, 150);
             }else{
                 enemy->kill();
                 if(!enemy->getAlive()){
                    delete enemy;
                 }
             }   
            }
        }
    }
}

void Game::render(float d_time){
    
    
    window.clear(sf::Color::Black);
    if(mario->getLifes() != 0){
        map->drawTile(window);
        mario->draw(window);
        enemy->draw(window);
        window.draw(camera->getText());
        window.draw(camera->getText2());
        window.draw(camera->getText3());
        window.draw(camera->getText4());
        window.draw(camera->getText5());
        window.draw(camera->getTextX());
        window.draw(camera->getCoin());
    }else{
        window.draw(camera->getText());
        window.draw(camera->getText2());
        window.draw(camera->getText3());
        window.draw(camera->getText4());
        window.draw(camera->getText5());
        window.draw(camera->getTextX());
        window.draw(camera->getCoin());
        window.draw(camera->getFin());
    }
    window.display();
}

void Game::cleared(){
 
    window.close();
}

void Game::run(){
    
    inicializar();
    float s = 0.f;
        while(isPlay){
            if(s >= 1.f/120.f){
                eventos();
                update();
                s = 0.f;
            }

            render(1.f/160.f);

            s+=1.f/120.f;
        }
        cleared();
    }