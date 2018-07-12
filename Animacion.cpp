#include <iostream>
#include <SFML/System/Vector2.hpp>

#include "Animacion.h"


//##########################################
//CONSUTRCTORES & DESTRUCTORES
//##########################################
Animacion::Animacion() {

}

Animacion::Animacion(const Animacion& orig) {
}

Animacion::~Animacion() {
}

//##########################################
//PRINCIPALES
//##########################################
void Animacion::inicializar(int ident, const char* fichero, sf::IntRect* coordenadas, sf::Vector2i* origenes, int num_fotogramas, int frames_por_segundo = 60, bool en_bucle = true)
{
    //Leer textura
    if(!textura.loadFromFile(fichero)){
        std::cerr << "Error al cargar la textura." << std::endl;
        exit(-1);
    }
    
    //Cargar fotogramas
    frames = new sf::Sprite[num_fotogramas];
    for(int i=0; i<num_fotogramas; i++){
       frames[i].setTexture(textura);                       //Cargar textura
       frames[i].setTextureRect(coordenadas[i]);            //Añadir rectángulo de la textura
       frames[i].setOrigin(origenes[i].x, origenes[i].y);   //Colocar origen
    }
    
    //Rellenar datos iniciales
    num_frames = num_fotogramas;
    frame_actual = 0;
    velocidad_frames = 1.0/frames_por_segundo;
    hasta_next_frame = velocidad_frames;
    bucle = en_bucle;
    id = ident;
}

void Animacion::set_posicion(float x, float y)
{
    for(int i = 0; i < num_frames; i++)
        frames[i].setPosition( x,  y);
}

void Animacion::set_origen(int x, int y, int pos) 
{
   //Si i == -1, entonces es a todos
    if(pos < 0)
    {
        for(int i = 0; i < num_frames; i++)
            frames[i].setOrigin( x,  y);
    }
    else
    {
        frames[pos].setOrigin( x,  y);  
    }
}

void Animacion::set_rotacion(float x)
{
    for(int i = 0; i < num_frames; i++)
        frames[i].setRotation( x);
}

void Animacion::set_tamanyo(float x, float y)
{
    for(int i = 0; i < num_frames; i++)
        frames[i].setScale( x, y);
}

void Animacion::move(float x, float y)
{
    for(int i = 0; i < num_frames; i++)
    {
        frames[i].move( x,  y);
    }
}

//Cambia y recoge datos
void Animacion::set_color(sf::Color c)
{
    color = c;    
    for(int i = 0; i < num_frames; i++)
        frames[i].setColor(color);
}

void Animacion::set_velocidad(int vel)
{
    velocidad_frames = 1.0/vel;
}

sf::Sprite Animacion::get_frame_actual(float dTime)
{
    //Vamos restando el tiempo hasta el siguiente frame
    hasta_next_frame -= dTime;
    
    //Si se acaba el contador, empieza el nuevo
    if(hasta_next_frame < 0)
    {
        hasta_next_frame = velocidad_frames;
        frame_actual++;
        if(frame_actual >= num_frames)
        {
            //Si es en bucle o no, empezamos desde el frame 0 o lo dejamos siempre en el último
            if(bucle == true)
            {
                frame_actual = 0;
            }else{
                frame_actual = num_frames - 1;
            }
        }
        
    }

    
    return frames[frame_actual];
}

sf::Vector2f Animacion::get_posicion()
{
    return frames[0].getPosition();
}

sf::FloatRect Animacion::get_global_bounds()
{
    return frames[0].getGlobalBounds();
}

int Animacion::get_id()
{
    return id;
}