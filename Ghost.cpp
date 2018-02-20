#include "Ghost.h"

Ghost::Ghost(){
    movement.x = 0.f;
    movement.y = 0.f;
    paused = false;
    alive = true;
    fila = 6;
    columna = 5;
    anterior.x = 1.f;
    anterior.y = 1.f;
    
    if(!textura.loadFromFile("/home/naru/Escritorio/ghostrojo.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }

    misprite.setTexture(textura);
    misprite.setPosition(300,300);
    misprite.setScale(sf::Vector2f(/*50.f/217.f,50.f/232.f*/0.3,0.3));
}
//aqui va la IA de los fantasmas
void Ghost::updatePos(Map* mapa){

    /*std::cout << "fila: " << columna << "\n";
    std::cout << "columna: " << fila << "\n";*/
    choque = false;
    
    //std::cout << "choque" << choque << "\n";
    if(mapa->intersecta(columna, fila)){ //si se encuentra en una interseccion
        int ran = (rand() % 4)+1; //num aleatorio entre 1 y 4
        //std::cout << "num random: " << ran << "\n";

        if(ran==1){ //arriba
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
                if(mapa->ocupada(columna,fila)){
                    columna--;
                    anterior = movement; //x
                    movement.x=0.f;
                    choque=true;
                }
            }else if(movement.x==-50.f){ //dcha
                columna--;
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

/*Ghost::kill(){
    
}

Ghost::pause(){
    
}

Ghost::restart(){
    
}

Ghost::resume(){
    
}

Ghost::~Ghost(){
    
}*/