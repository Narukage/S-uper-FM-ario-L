#include "Pacman.h"

//inicializar variables y aplicar textura en el constructor??
Pacman::Pacman(){
    
    /*current_pos.x = 250.f;
    current_pos.y = 250.f;
    dir_move.x = 0.f;
    dir_move.y = 0.f;*/
    playerSpeed = 1.f;
    movement.x = 0.f;
    movement.y = 0.f;
    direction_ = Right; //empieza mirando a la derecha
    paused = false;
    alive = true;
    score = 0;
    fila = 1;
    columna = 1;
    vidas = 3;

    if(!textura.loadFromFile("/home/naru/Escritorio/Pac-Man_sprite.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }

    misprite.setTexture(textura);
    misprite.setPosition(100,50);
    misprite.setScale(sf::Vector2f(/*50.f/217.f,50.f/232.f*/0.3,0.3));
    
    //texto de score
    if(!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeMono.ttf")){
        std::cout << "Fuente no aplicada" <<std::endl;
    }
    
    text.setFont(font);
    text.setPosition(620,0);
    text.setColor(sf::Color::Red);
    text.setString("Score:");
    
    text2.setFont(font);
    text2.setPosition(620,70);
    text2.setColor(sf::Color::Red);
    text2.setString("Lifes:");
    
     if (!buffer.loadFromFile("/home/naru/Escritorio/jrdot1.wav")){
        std::cout << "No pudo abrir el archivo de audio" << "\n";
    }
    
    if (!buffer2.loadFromFile("/home/naru/Escritorio/pacman_death.wav")){
        std::cout << "No pudo abrir el archivo de audio" << "\n";
    }
    
    if (!buffer3.loadFromFile("/home/naru/Escritorio/siren.wav")){
        std::cout << "No pudo abrir el archivo de audio" << "\n";
    }
    
    sound3.setVolume(70);
    sound3.setBuffer(buffer3);
    
    sound.setVolume(70);
    sound.setBuffer(buffer);
    
    sound2.setVolume(70);
    sound2.setBuffer(buffer2);
    
    

}

sf::Text Pacman::getPuntos(){
    std::stringstream ss;
    ss << score;
    mytext.setString(ss.str().c_str());
    mytext.setColor(sf::Color::Red);
    mytext.setFont(font);
    mytext.setPosition(750,0);
    
    return mytext;
}

sf::Sprite Pacman::getVidas(){
    if(vidas==3){
        if(!textura.loadFromFile("/home/naru/Escritorio/3vidas.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
        
    vida.setTexture(textura);
    vida.setPosition(645,120);
    vida.setScale(sf::Vector2f(/*50.f/217.f,50.f/232.f*/0.2,0.2));
    
    }
    
    if(vidas==2){
        if(!textura.loadFromFile("/home/naru/Escritorio/2vidas.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
        
    vida.setTexture(textura);
    vida.setPosition(645,120);
    vida.setScale(sf::Vector2f(/*50.f/217.f,50.f/232.f*/0.2,0.2));
    }
    
    if(vidas==1){
        if(!textura.loadFromFile("/home/naru/Escritorio/Pac-Man_sprite.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }
        
    vida.setTexture(textura);
    vida.setPosition(645,120);
    vida.setScale(sf::Vector2f(/*50.f/217.f,50.f/232.f*/0.2,0.2));
    }
    
    return vida;
    
}

void Pacman::updatePos(int presionado, Map* mapa){ //multiplico por 50 porque cada posicion de la matriz son 50x50 pixeles
    
    /*dir_move.x=0.f;
    dir_move.y=0.f;*/
    //std::cout << "cont: " << cont << "\n";
    if(cont == 3){
      sound3.play();
      cont = 0;
    }
    cont++;
    
    /*std::cout << "fila" << columna << "\n";
    std::cout << "columna" << fila << "\n";*/
         
    if(presionado==1){ //A
         /*dir_move.x=-1.f;
         dir_move.y=0.f;*/
        columna--;
        if(columna==-1 && fila==8){
            columna=10;
            fila=8;
            misprite.setPosition(600,400);
            std::cout << "aqui en la esquina" << "\n";
        }
        if(mapa->ocupada(columna,fila)){
            columna++;
            movement.x = 0.f;
        }else{
            movement.x =-50.f;
            movement.y = 0.f;
        }
        if(mapa->hayCoco(columna,fila)){
            score++;
            sound.play();
        }
    }
    
    if(presionado==2){ //D
         /*dir_move.x=1.f;
         dir_move.y=0.f;*/
        columna++;        
        if(columna==11 && fila==8){
            columna=0;
            fila=8;
            misprite.setPosition(0,400);
        }
        if(mapa->ocupada(columna,fila)){
            columna--;
            movement.x = 0.f;
        }else{
            movement.x =50.f;
            movement.y = 0.f;
        }
    if(mapa->hayCoco(columna,fila)){
        score++;
        sound.play();
        }
    }
    
    if(presionado==3){ //S
         /*dir_move.x=0.f;
         dir_move.y=1.f;*/
        fila++;
        if(mapa->ocupada(columna,fila)){
            fila--;
            movement.y = 0.f;
        }else{
            movement.x = 0.f;
            movement.y =50.f;
        }
        if(mapa->hayCoco(columna,fila)){
            score++;
            sound.play();
        }
    }
    
    
    if(presionado==4){ //W
         /*dir_move.x=0.f;
         dir_move.y=-1.f;*/
        fila--;
        if(mapa->ocupada(columna,fila)){
            fila++;
            movement.y = 0.f;
        }else{
            movement.y =-50.f;
            movement.x = 0.f;
        }
        if(mapa->hayCoco(columna,fila)){
            score++;
            sound.play();
        }
    }
    
    if(presionado!=0){
        misprite.move(movement);
    }
    movement.x = 0.f;
    movement.y = 0.f;
    
    if(score==59){
        win=true;
    }
}

void Pacman::interpolate(float d_time, Map* mapa){
    
    //Old position
    /*sf::Vector2f oldpos = current_pos;
    
    //Calculate new pos
    current_pos.x += dir_move.x * playerSpeed * d_time;
    current_pos.y += dir_move.y * playerSpeed * d_time;
        
    //Antigua pos
    if(!mapa->ocupada(current_pos.x, current_pos.y))
    {
        misprite.setPosition(current_pos);        
    }else{
        //Restore position
        current_pos = oldpos;
    }
    
    misprite.setPosition(current_pos);*/
    
    //volver a programar el movimiento original sin interpolacion
    //hacer funcion en mapa para controlar la posicion de pacman en la matriz
    //llamar a la funcion y pasarle 1 o -1 a i o j para cambiar posicion en matriz
}

sf::Sprite Pacman::getSprite(){
    return misprite;
}

float Pacman::getVelocity(){
    return playerSpeed;
}

void Pacman::setDirection(Pacman::Direction direction){
    if(direction!=direction_){
        direction_=direction;
    }
}

void Pacman::pause(){
    
}

void Pacman::restart(){
    
}

void Pacman::resume(){
    
}

void Pacman::kill(sf::RenderWindow& window, bool& isPlay){
    alive = false;
    vidas--;
    sound2.play();
    if(vidas==0){
    //estado del juego a derrota
     isPlay = false;
    //fin del juego
    }
    //animacion de morir
    misprite.setPosition(100,50); //recolocacion de pacman en su posicion inicial
    movement.x = 0.f;
    movement.y = 0.f;
    fila = 1;
    columna = 1;
    alive = true;
}

bool Pacman::isAlive(){
    if(alive){
        return true;
    }else{
        return false;
    }
}

int Pacman::getScore(){
    return score;
}

sf::Vector2f Pacman::getCurrentPosition(){
    return current_pos;
}

Pacman::~Pacman(){
    
}

const sf::Sprite &Pacman::getSprite() const{
    return misprite;
}




