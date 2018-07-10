//##########################################
//COSAS POR HACER::
//> Input de teclado
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
    //Inicializar el dibuja todo
    render_fachada = &Render_Fachada::instancia();
    render_fachada->inicializar(800, 600, "Digger", 60, true);
    
    //Inicializar variables
    jugando = true;
}

//Actualizarlo todo
void Juego::actualizar()
{
    //Actualizar fachadas
    render_fachada->actualizar();
    
    //Acciones de teclas (cerrar juego)
    ultima_tecla = render_fachada->getPresionado();
    if(ultima_tecla == Render_Fachada::Presionado::Salir)
    {
        jugando = false;
    }

}

void Juego::dibujar(float dTime)
{
    render_fachada->dibujar(dTime);
}

//Funcion principal que corre el juego
void Juego::correr()
{
    //Inicializa todo
    inicializar();
    float tiempo = 0.f;
    
    //Bucle principal
    while(jugando)
    {
        //Update cada 4 frames
        float tiempoDibujado = reloj.tiempoTranscurrido();
        tiempo += tiempoDibujado;
        if(tiempo >= 1/15.f)
        {
            actualizar();
            tiempo = 0.f;
        }
        
        dibujar(tiempoDibujado);
    }
}

    