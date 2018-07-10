//##########################################
//COSAS POR HACER::
//> Pintado de sprites
//> Animaciones
//> Patrón de estados
//> Control y movimiento de personaje por pantalla
//> Sistema de puntos
//> Pintado por xml
//> Colisiones de enemigos por pixel
//> Consumir paredes con pintado de fondo por pixel (sencillito)
//> IA de los enemigos 
//> Hacer dos niveles
//> Managers
//> Musica (?)

#include "Juego.h"

//##########################################
//CONSUTRCTORES & DESTRUCTORES
//##########################################
Juego::Juego() {
}

Juego::Juego(const Juego& orig) {
}

Juego::~Juego() {
}

//##########################################
//PRINCIPALES
//##########################################

//funcion para inicializar todas las variables del juego
void Juego::inicializar()
{
    //Inicializar variables
    jugando = true;
    
    //Estado actual
    estado_actual = &EIntro::instancia();
    estado_actual->inicializar();
}

//Funcion principal que corre el juego
void Juego::correr()
{
    //Inicializa todo
    inicializar();
    float tiempo = 0.f;
    
    //Bucle principal
    while(estado_actual->jugando)
    {
        //Update cada 4 frames
        float tiempoDibujado = reloj.tiempoTranscurrido();
        tiempo += tiempoDibujado;
        if(tiempo >= 1/15.f)
        {
            estado_actual->actualizar();
            tiempo = 0.f;
        }
        
        estado_actual->dibujar(tiempoDibujado);
    }
}

//Limpiar toda la memoria sobrante
void Juego::limpiar()
{
    
}

void Juego::cambia_estado(EState::Estado_tipo tipo)
{
    if(tipo == EState::Estado_tipo::INTRO)
        estado_actual = &EIntro::instancia();
    
    if(tipo == EState::Estado_tipo::PANTALLA1)
        estado_actual = &EPantalla1::instancia();
    
    if(tipo == EState::Estado_tipo::PANTALLA2)
        estado_actual = &EPantalla2::instancia();
    
    estado_actual->inicializar();
}