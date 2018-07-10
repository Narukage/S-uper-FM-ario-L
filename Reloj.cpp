#include <SFML/System/Clock.hpp>

#include "Reloj.h"

//##########################################
//CONSUTRCTORES & DESTRUCTORES
//##########################################

Reloj::Reloj() {
}

Reloj::Reloj(const Reloj& orig) {
}

Reloj::~Reloj() {
}

//##########################################
//PRINCIPALES
//##########################################
float Reloj::tiempoTranscurrido()
{
    sf::Time tiempo = reloj.getElapsedTime();
    reloj.restart();
    return tiempo.asSeconds();
}