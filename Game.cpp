#include "Game.h"


Game::Game(): window(sf::VideoMode(800,600),"Ventana de SFML"){
   
}

Game::~Game(){
    delete pacman;
    delete mapa;
    delete collision;
    delete fantasma1;
    delete fantasma2;
}

void Game::inicializar(){
    
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    //crear pacman
    pacman = new Pacman();
    //crear mapa
    mapa = new Map();
    collision = new CollisionManager();
    //state = new StateManager();
    //crear fantasmas
    fantasma1 = new Ghost(1);
    fantasma2 = new Ghost(2);
    /*fantasma2 = new Ghost();
    fantasma3 = new Ghost();*/
    //crear objetos
    
    if(!texturagameover.loadFromFile("assets/gameover.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    
    if(!texturaready.loadFromFile("assets/ready.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
    
    ready.setTexture(texturaready);
    ready.setPosition(260,100);
    ready.setScale(3,3);
    
    mensaje.setTexture(texturagameover);
    mensaje.setPosition(280,250);
    mensaje.setScale(3,3);
    
    if (!buffer.loadFromFile("/home/naru/Escritorio/pacman_beginning.wav")){
        std::cout << "No pudo abrir el archivo de audio" << "\n";
    }
    
    sound.setVolume(70);
    sound.setBuffer(buffer);
    
    deltaTime = 0.0f;
    
    textureSize2 = texturamorir.getSize();
    textureSize2.x /= 11;
    textureSize2.y /= 1;
    
    animation = new Animation(&texturamorir, sf::Vector2u(3.5,1), 2.0f);
  
    
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
    std::cout << pacman->isAlive() << "\n";
    
    if(pacman->getWin()){
        isPlay=false;
    }
    if(cont2==1){  
        pacman->updatePos(presionado, mapa, deltaTime);  //Actualizamos posición personaje
        //presionado = none;                              //Estado de movimiento = 0
        cont2=0;
    }
    cont2++;
    if(cont==2){ //preguntar por que core dumped por hacer un contador
        fantasma1->updatePos(mapa, deltaTime);
        cont = 0;
    }
    cont ++;
    if(collision->checkSpriteCollision(pacman->getSprite(),fantasma1->getSprite())&&pacman->isAlive()){
        pacman->kill(window, isPlay, deltaTime);
        std::cout << "Te han matao" << "\n";
    }
    
    if(!pacman->isAlive()){
        animation->Update(0, deltaTime);
        pacman->getSprite().setTextureRect(animation->uvRect);
        control+=clock.getElapsedTime().asSeconds();
        clock.restart();
        
        if(control>1.1f){
            pacman->restart();
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
        window.draw(fantasma1->getSprite());
        if(contready<100){
            window.draw(ready);
            contready++;
        }
    }else{
        window.draw(pacman->getSprite());
        window.draw(mensaje);
    }
    
    window.display();
}

void Game::cleared(){
 
    window.close();
}

void Game::run(){
    
    inicializar();
    float s = 0.f;
    sound.play();
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