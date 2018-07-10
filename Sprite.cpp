#include <iostream>

#include "Sprite.h"

#include <SFML/System/Vector2.hpp>

//##########################################
//CONSUTRCTORES & DESTRUCTORES
//##########################################
Sprite::Sprite() {
}

Sprite::Sprite(const Sprite& orig) {
}

Sprite::~Sprite() {
}

//##########################################
//PRINCIPALES
//##########################################
void Sprite::inicializar(int ident, std::string fichero, sf::IntRect coordenadas, sf::Vector2i origen)
{
    //Leer textura
    if(!textura.loadFromFile(fichero)){
        std::cout << "Error al cargar la textura." << std::endl;
        exit(-1);
    }
    
    //Cargar fotogramas
    sprite.setTexture(textura);                       //Cargar textura
    sprite.setTextureRect(coordenadas);            //Añadir rectángulo de la textura
    sprite.setOrigin(origen.x, origen.y);   //Colocar origen
       
    //Rellenar datos iniciales
    id = ident;
}

void Sprite::set_posicion(float x, float y)
{
    sprite.setPosition( x,  y);
}

void Sprite::set_origen(int x, int y) 
{
   
    sprite.setOrigin( x,  y);  
    
}

void Sprite::set_rotacion(float x)
{
    sprite.setRotation( x);
}

void Sprite::set_tamanyo(float x, float y)
{
    sprite.setScale( x,  y);
}

//Cambia y recoge datos
void Sprite::set_color(sf::Color c)
{
    color = c;
    sprite.setColor(color);
}

sf::Sprite Sprite::get_sprite()
{
    return sprite;
}

sf::Vector2f Sprite::get_posicion()
{
    return sprite.getPosition();
}

int Sprite::get_id()
{
    return id;
}