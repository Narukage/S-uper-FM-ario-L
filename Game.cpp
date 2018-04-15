#include "Game.h"


Game::Game(): window(sf::VideoMode(800,600),"Ventana de SFML"){
   
}

Game::~Game(){
    delete pacman;
    delete mapa;
    delete collision;
    delete fantasma1;
    delete fantasma2;
    delete fantasma3;
    delete animation;
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
    fantasma1 = new Ghost(1);
    fantasma2 = new Ghost(2);
    fantasma3 = new Ghost(3);
    //crear objetos
    
    if(!texturagameover.loadFromFile("assets/gameover.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    
    if(!texturavacio.loadFromFile("assets/vacio.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    
    if(!texturaready.loadFromFile("assets/ready.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    
    if(!texturamorir.loadFromFile("assets/morir.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    
    ready.setTexture(texturaready);
    ready.setPosition(260,100);
    ready.setScale(3,3);
    
    mensaje.setTexture(texturagameover);
    mensaje.setPosition(280,250);
    mensaje.setScale(3,3);
    
    if (!buffer.loadFromFile("music/intro.wav")){
        std::cout << "No pudo abrir el archivo de audio" << "\n";
    }
    
    sound.setVolume(70);
    sound.setBuffer(buffer);
    
    if (!buffer2.loadFromFile("music/death.wav")){
        std::cout << "No pudo abrir el archivo de audio" << "\n";
    }
    
    if (!buffer3.loadFromFile("music/ghost.wav")){
        std::cout << "No pudo abrir el archivo de audio" << "\n";
    }
    
    sound2.setVolume(70);
    sound2.setBuffer(buffer2);
    
    sound3.setVolume(70);
    sound3.setBuffer(buffer3);
    
    deltaTime = 0.0f;
    
    textureSize2 = texturamorir.getSize();
    textureSize2.x /= 2;
    textureSize2.y /= 6;
    
    morir.setTexture(texturamorir);
    morir.setScale(3,3);
    
    animation = new Animation(&texturamorir, sf::Vector2u(2.5,6), 0.2f);

  
    
}

void Game::eventos(){
    
    deltaTime = clock.restart().asSeconds();
    
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
                        
                        if(evento.key.code==sf::Keyboard::Q || evento.key.code==sf::Keyboard::Escape){
                            isPlay = false;
                        }else{
                            presionado = none;
                        }

                }
    }
}

void Game::update(){
    if(pacman->getWin()){
        isPlay=false;
    }
        if(pacman->isAlive()){
            pacman->updatePos(presionado, mapa, deltaTime);  //Actualizamos posición personaje
            //presionado = none;                              //Estado de movimiento = 0
        }
    if(cont==2){ //preguntar por que core dumped por hacer un contador
        fantasma1->updatePos(mapa, deltaTime, pacman->getEstadoCaza());
        fantasma2->updatePos(mapa, deltaTime, pacman->getEstadoCaza());
        fantasma3->updatePos(mapa, deltaTime, pacman->getEstadoCaza());
        cont = 0;
    }
    cont ++;
    if(clock2.getElapsedTime().asSeconds()>2.5){
    if(collision->checkSpriteCollision(pacman->getSprite(),fantasma1->getSprite())&&pacman->isAlive()){
        clock2.restart();
        if(!pacman->getEstadoCaza()){
            pacman->kill();
            if(pacman->getVidass()==0){
                sound2.play();
            }
            std::cout << "Te han matao" << "\n";
            pacman->restart();
        }else{
            fantasma1->kill(fantasma1->getColor());
            sound3.play();
            pacman->setEstadoCaza(false);
            
        }
    }
    
    if(collision->checkSpriteCollision(pacman->getSprite(),fantasma2->getSprite())&&pacman->isAlive()){
        clock2.restart();
        if(!pacman->getEstadoCaza()){
            pacman->kill();
            if(pacman->getVidass()==0){
                sound2.play();
            }
            std::cout << "Te han matao" << "\n";
            
            pacman->restart();
        }else{
            fantasma2->kill(fantasma2->getColor());
            sound3.play();
            pacman->setEstadoCaza(false);
        }
    }
    
    if(collision->checkSpriteCollision(pacman->getSprite(),fantasma3->getSprite())&&pacman->isAlive()){
        clock2.restart();
        if(!pacman->getEstadoCaza()){
            pacman->kill();
            if(pacman->getVidass()==0){
                sound2.play();
            }
            std::cout << "Te han matao" << "\n";
            pacman->restart();
        }else{
            fantasma3->kill(fantasma3->getColor());
            sound3.play();
            pacman->setEstadoCaza(false);
        }
    }
    }
}

void Game::render(float d_time){
    
    window.clear(sf::Color::Black);
    sf::Vector2f current_pos = pacman->getCurrentPosition();
    
    if(pacman->getVidass()!=0){//pacman->interpolate(d_time, mapa);
        window.draw(pacman->getSprite());
        window.draw(pacman->getText());
        window.draw(pacman->getTextVidas());
        window.draw(pacman->getPuntos());
        window.draw(pacman->getVidas());
        //dibujar mapa
        mapa->printMap(window);
        //dibujar fantasmas
        if(fantasma1->isAlive()){
            window.draw(fantasma1->getSprite());
        }
        if(fantasma2->isAlive()){
            window.draw(fantasma2->getSprite());
        }
        if(fantasma3->isAlive()){
            window.draw(fantasma3->getSprite());
        }
        if(contready<50){
            window.draw(ready);
            contready++;
        }
    }else{
        
        control+=clock.getElapsedTime().asSeconds();
        clock.restart();
        
        morir.setPosition(pacman->getSprite().getPosition());
        animation->Update(0, deltaTime);
        morir.setTextureRect(animation->uvRect);
        
        if(control>0.1){
            animation->Update(1, deltaTime);
            morir.setTextureRect(animation->uvRect);    
        }
        if(control>0.2){
            animation->Update(2, deltaTime);
            morir.setTextureRect(animation->uvRect);
        }
        if(control>0.3){
            animation->Update(3, deltaTime);
            morir.setTextureRect(animation->uvRect);
        }
        if(control>0.4){
            animation->Update(5, deltaTime);
            morir.setTextureRect(animation->uvRect);
        }
        if(control>0.6){
            morir.setTexture(texturavacio);
        }
        window.draw(morir);
        window.draw(mensaje);
    }
    window.display();
    if(control>7){
        isPlay=false;
    }
}

void Game::cleared(){
 
    window.close();
}

void Game::run(){
    
    inicializar();
    float s = 0.f;
    sound.play();
    render(1.f/120.f);
    while(clock.getElapsedTime().asSeconds()<4.5){
        
    }
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