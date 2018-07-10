/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Animacion.cpp
 * Author: alexei
 * 
 * Created on 9 de julio de 2018, 19:14
 */

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
void Animacion::inicializar(std::string fichero, sf::IntRect* coordenadas, sf::Vector2i* origenes, int num_fotogramas, int frames_por_segundo = 60, bool en_bucle = true)
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
    bucle = en_bucle;
}

void Animacion::set_posicion(float x, float y)
{
    for(int i = 0; i < num_frames; i++)
        frames[i].setPosition(float x, float y);
}

void Animacion::set_origen(int x, int y, int pos) 
{
   //Si i == -1, entonces es a todos
    if(pos < 0)
    {
        for(int i = 0; i < num_frames; i++)
            frames[i].setPosition(float x, float y);
    }
    else
    {
        frames[pos].setPosition(float x, float y);  
    }
}

void Animacion::set_rotacion(float x)
{
    for(int i = 0; i < num_frames; i++)
        frames[i].setRotation(float x);
}

void Animacion::set_tamanyo(float x, float y)
{
    for(int i = 0; i < num_frames; i++)
        frames[i].setScale(float x, float y);
}

//Cambia y recoge datos
void Animacion::set_color(sf::Color c)
{
    color = c;
}

void Animacion::set_velocidad(int vel)
{
    velocidad_frames = 1.0/vel;
}

int Animacion::get_frame_actual()
{
    return frame_actual;
}
sf::Vector2f Animacion::get_posicion()
{
    return frames[0].getPosition();
}