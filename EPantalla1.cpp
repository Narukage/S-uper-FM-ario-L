
#include "EPantalla1.h"
#include <iostream>


EPantalla1::EPantalla1() {
}

EPantalla1::EPantalla1(const EPantalla1& orig) {
}

EPantalla1::~EPantalla1() {
}


//##########################################
//PRINCIPALES
//##########################################
void EPantalla1::inicializar()
{    
    //Inicializar el dibuja todo
    render_fachada = &Render_Fachada::instancia();
    
    //Inicializar variables
    jugando = true;
    
    //Crear mapa
    
    //Crear personaje
    digger = new Digger();
    sf::IntRect* lista_digger = new sf::IntRect[2];
    lista_digger[0] = sf::IntRect(4,3,16,23);
    lista_digger[1] = sf::IntRect(45,3,16,23);
    sf::Vector2i* origenes_digger = new sf::Vector2i[2];
    origenes_digger[0] = sf::Vector2i(8, 12);
    origenes_digger[1] = sf::Vector2i(8, 12);
    digger->animacion = render_fachada->Anyadir_animacion("assets/sprites/digger_sprite.png", lista_digger, origenes_digger, 2, 10, true);
    render_fachada->Mover_animacion(digger->animacion, 10, 10);
    
    //Crear enemigos
}

void EPantalla1::actualizar()
{
    render_fachada->actualizar();
    
    
    
    //Salida de emergencia
    if(ultima_tecla == Render_Fachada::Presionado::Salir)
    {
        jugando = false;
    }
}

void EPantalla1::dibujar(float dTime)
{
    render_fachada->dibujar(dTime);
}

void EPantalla1::limpiar()
{
    //Eliminar elementos creados
    delete digger;
}