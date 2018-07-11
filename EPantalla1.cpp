
#include "EPantalla1.h"
#include <iostream>

#include "Animacion.h"
#include "Sprite.h"

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
    digger->animacion_sprite = render_fachada->Devolver_animacion(digger->animacion);
    digger->animacion_sprite->set_tamanyo(50/16,50/23);
    digger->animacion_sprite->set_posicion(50,50);
    
    //Crear enemigos
    
    //Cargar mapa
    //render_fachada->cargar_mapa(0);
    mapa = new Mapa();
    mapa->cargar_mapa(0);
    
    //Marcador
    puntos_actuales = 0;
    puntos_ganar = 500;
}

void EPantalla1::actualizar()
{
    render_fachada->actualizar();
    
    //Acciones de teclas (mover personaje)
    ultima_tecla = render_fachada->getPresionado();
    
    //Control del personaje
    digger->mover(ultima_tecla);
    
    //Eliminar casillas
    puntos_actuales += mapa->eliminar_casilla(digger->animacion_sprite->get_posicion());
    
    
    std::cout<<"Puntos: "<<puntos_actuales<<"/"<<puntos_ganar<<std::endl;
    //Salida de emergencia
    if(ultima_tecla == Render_Fachada::Presionado::Salir)
    {
        jugando = false;
    }
    
}

void EPantalla1::dibujar(float dTime)
{
    //Interpolar posiciones
    digger->moverInterpolado(dTime);
    
    //Dibujar
    render_fachada->dibujar(dTime);
}

void EPantalla1::limpiar()
{
    //Eliminar elementos creados
    delete digger;
}