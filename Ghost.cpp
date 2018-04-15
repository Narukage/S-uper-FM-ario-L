#include "Ghost.h"


Ghost::Ghost(int color){
    color = color;
    movement.x = 0.f;
    movement.y = 0.f;
    paused = false;
    alive = true;
    anterior.x = 1.f;
    anterior.y = 1.f;
    
    if(color==1){
        fila = 6;
        columna = 5;
        if(!textura.loadFromFile("assets/animacionghost.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
 
        if(!texturaghost.loadFromFile("assets/ghost.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }

        misprite.setTexture(texturaghost);
        misprite.setPosition(300,300);
        misprite.setScale(sf::Vector2f(3,3));
     
        textureSize = textura.getSize();
        textureSize.x /= 2;
        textureSize.y /= 4;
    
    animation = new Animation(&textura, sf::Vector2u(2,4), 0.2f);
    }
    
    if(color==2){
        fila = 6;
        columna = 5;
        if(!textura.loadFromFile("assets/animacionghost2.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        
        if(!texturaghost.loadFromFile("assets/ghost2.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        
        misprite.setTexture(texturaghost);
        misprite.setPosition(300,300);
        misprite.setScale(sf::Vector2f(3,3));
        
        textureSize = textura.getSize();
        textureSize.x /= 2;
        textureSize.y /= 4;
        
        animation = new Animation(&textura, sf::Vector2u(2,4), 0.2f);
    }
    
    if(color==3){
        fila = 6;
        columna = 5;
        if(!textura.loadFromFile("assets/animacionghost3.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        
        if(!texturaghost.loadFromFile("assets/ghost3.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
        
        misprite.setTexture(texturaghost);
        misprite.setPosition(300,300);
        misprite.setScale(sf::Vector2f(3,3));
        
        textureSize = textura.getSize();
        textureSize.x /= 2;
        textureSize.y /= 4;
        
        animation = new Animation(&textura, sf::Vector2u(2,4), 0.2f);
        
    }
    
    if(!texturacaza.loadFromFile("assets/run.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }
    
    textureSize2 = texturacaza.getSize();
    textureSize2.x /= 2;
    textureSize2.y /= 1;
    
    animation2 = new Animation(&texturacaza, sf::Vector2u(2,1), 0.2f);
    
    /*if(color==2){
        if(!textura2.loadFromFile("/home/naru/Escritorio/ghost.png")){
               std::cout<<"Textura no aplicada"<<std::endl;
            }

        misprite2.setTexture(textura2);
        misprite2.setPosition(300,300);
        misprite2.setScale(sf::Vector2f(0.3,0.3));
    }*/
}
//aqui va la IA de los fantasmas
void Ghost::updatePos(Map* mapa, float deltaTime, bool estadocaza){

    if(!estadocaza){
        misprite.setTexture(textura);
    }else{
        misprite.setTexture(texturacaza);
    }
    
    /*std::cout << "fila: " << columna << "\n";
    std::cout << "columna: " << fila << "\n";*/
    choque = false;
    
    //std::cout << "choque" << choque << "\n";
    if(mapa->intersecta(columna, fila)){ //si se encuentra en una interseccion
        //reinisiar el taiming a tzero
        if(color==1)
        srand(time(NULL));
        int ran = (rand() % 4)+1; //num aleatorio entre 1 y 4 (GENERAR NUMERO REAL WTF)

        if(ran==1){ //arriba
            if(!estadocaza){
                animation->Update(0, deltaTime);
                misprite.setTextureRect(animation->uvRect);
            }else{
                animation2->Update(0, deltaTime);
                misprite.setTextureRect(animation2->uvRect); 
            }
            fila--;
            if(mapa->ocupada(columna,fila)){
                fila++;
                anterior = movement; //y
                movement.y=0.f;
                movement.x=0.f;
                choque=true;
            }else{
                movement.y =-50.f;
                movement.x = 0.f;
            }
        }else 

        if(ran==2){ //abajo
            if(!estadocaza){
                animation->Update(1, deltaTime);
                misprite.setTextureRect(animation->uvRect);
            }else{
                animation2->Update(0, deltaTime);
                misprite.setTextureRect(animation2->uvRect); 
            }
                fila++;
            if(mapa->ocupada(columna,fila)){
                fila--;
                anterior = movement;//y
                movement.y=0.f;
                movement.x=0.f;
                choque=true;
            }else{
                movement.x = 0.f;
                movement.y =50.f;
            }
        }else

        if(ran==3){ //izquierda
            if(!estadocaza){
                animation->Update(2, deltaTime);
                misprite.setTextureRect(animation->uvRect);
            }else{
                animation2->Update(0, deltaTime);
                misprite.setTextureRect(animation2->uvRect); 
            }
                columna--;
            if(mapa->ocupada(columna,fila)){
                columna++;
                anterior = movement; //x
                movement.x=0.f;
                movement.y=0.f;
                choque=true;
            }else{
                movement.x =-50.f;
                movement.y = 0.f;
            }
        }else 

        if(ran==4){ //derecha
            if(!estadocaza){
                animation->Update(3, deltaTime);
                misprite.setTextureRect(animation->uvRect);
            }else{
                animation2->Update(0, deltaTime);
                misprite.setTextureRect(animation2->uvRect); 
            }
                columna++;
            if(mapa->ocupada(columna,fila)){
                columna--;
                anterior = movement; //x
                movement.x=0.f;
                movement.y=0.f;
                choque=true;
            }else{
                movement.x =50.f;
                movement.y = 0.f;
            }
        }
         misprite.move(movement);

    }else{ //si no se encuentra en una interseccion
        if (cont == 0){ // si es el primer movimiento de la partida
            //std::cout << "primer mov" << "\n";
            fila--;
            movement.y=-50.f; //se mueve hacia arriba
            misprite.move(movement);
            cont++;
        }else{

            //std::cout << "sigo" << "\n";
                                     //hasta llegar a una interseccion
            //actualizar posicion en la matriz
            if(movement.y==-50.f){ //arriba
                fila--;
                if(mapa->ocupada(columna,fila)){
                    fila++;
                    anterior = movement; //y
                    movement.y=0.f;
                    choque=true;
                }

            }else if(movement.y==50.f){ //abajo
                fila++;
                if(mapa->ocupada(columna,fila)){
                    fila--;
                   anterior = movement;//y
                   movement.y=0.f;
                   choque=true;
                }
            }else if(movement.x==50.f){ //izq
                columna++;
                if(columna==11 && fila==8){
                    columna=0;
                    fila=8;
                    misprite.setPosition(0,400);
                 }
                if(mapa->ocupada(columna,fila)){
                    columna--;
                    anterior = movement; //x
                    movement.x=0.f;
                    choque=true;
                }
            }else if(movement.x==-50.f){ //dcha
                columna--;
               if(columna==-1 && fila==8){
                    columna=10;
                    fila=8;
                    misprite.setPosition(600,400);
                }
                if(mapa->ocupada(columna,fila)){
                    columna++;
                    anterior = movement; //x
                    movement.x=0.f;
                    choque=true;
                }
            }
            
            /*std::cout << "anteriorx: " << anterior.x << "\n";
            std::cout << "anteriory: " << anterior.y << "\n";
            std::cout << "movimiento en x: " << movement.x << "\n";
            std::cout << "movimiento en y: " << movement.y << "\n";*/


            
            if((movement.x==0.f || movement.y==0.f) && choque){
                if(!mapa->ocupada(columna-1, fila) && anterior.x!=50.f && choque){
                    //hueco de la izquierda libre
                    // and no me estaba moviendo a la izq
                    columna--;
                    movement.x=-50.f;
                    choque=false;
                }
                if((!mapa->ocupada(columna, fila-1) && anterior.y!=-50.f)&&choque){
                    //hueco de la arriba libre
                    // and no me estaba moviendo a arriba
                    movement.y=-50.f;
                    fila--;
                    choque = false;

                }
                if(!mapa->ocupada(columna+1, fila) && anterior.x!=-50.f && choque){
                    //hueco de la dcha libre
                    // and no me estaba moviendo a la dcha
                    movement.x=50.f;
                    columna++;
                    choque = false;

                    
                }
                if(!mapa->ocupada(columna, fila+1) && anterior.y!=50.f && choque){
                    //hueco de la abajo libre
                    // and no me estaba moviendo a abajo
                    movement.y=50.f;
                    fila++;
                    choque = false;

                }
            }
          misprite.move(movement);
        }
    }
    
}

/*Ghost::getCurrentPosition(){
    
}*/

sf::Sprite Ghost::getSprite(){
    return misprite;
}

bool Ghost::isAlive(){
    return alive;
}

void Ghost::kill(int color){
    if(this->color==color){
        alive=false;
    }
}

/*Ghost::pause(){
    
}

Ghost::restart(){
    
}

Ghost::resume(){
    
}
*/
Ghost::~Ghost(){
    delete animation;
    delete animation2;
}