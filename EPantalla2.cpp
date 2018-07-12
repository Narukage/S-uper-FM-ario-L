#include "EPantalla2.h"

#include <iostream>

#include "Animacion.h"
#include "Sprite.h"
#include "Juego.h"

EPantalla2::EPantalla2() {
}

EPantalla2::EPantalla2(const EPantalla2& orig) {
}

EPantalla2::~EPantalla2() {
}

//##########################################
//PRINCIPALES
//##########################################

void EPantalla2::inicializar()
{    //Inicializar el dibuja todo
    render_fachada = &Render_Fachada::instancia();
    render_fachada->cargarHUD();
    
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
    digger->animacion_sprite->set_posicion(100,100);
    
    //Crear enemigos
    enemigo = new Enemigo();
    sf::IntRect* lista_enemigo = new sf::IntRect[2];
    lista_enemigo[0] = sf::IntRect(4,2,16,15);
    lista_enemigo[1] = sf::IntRect(45,2,16,15);
    sf::Vector2i* origenes_enemigo = new sf::Vector2i[2];
    origenes_enemigo[0] = sf::Vector2i(8, 8);
    origenes_enemigo[1] = sf::Vector2i(8, 8);
    enemigo->animacion = render_fachada->Anyadir_animacion("assets/sprites/enemigo1_sprite.png", lista_enemigo, origenes_enemigo, 2, 10, true);
    enemigo->animacion_sprite = render_fachada->Devolver_animacion(enemigo->animacion);
    enemigo->animacion_sprite->set_tamanyo(50/16,50/15);
    enemigo->animacion_sprite->set_posicion(300, 500);
    enemigo->velocidad_x = 120;
    enemigo->velocidad_y = 50;
    
    enemigo2 = new Enemigo();
    enemigo2->animacion = render_fachada->Anyadir_animacion("assets/sprites/enemigo1_sprite.png", lista_enemigo, origenes_enemigo, 2, 10, true);
    enemigo2->animacion_sprite = render_fachada->Devolver_animacion(enemigo2->animacion);
    enemigo2->animacion_sprite->set_tamanyo(50/16,50/15);
    enemigo2->animacion_sprite->set_posicion(500, 500);
    enemigo2->velocidad_x = 60;
    enemigo2->velocidad_y = 60;
    
    //Cargar mapa
    //render_fachada->cargar_mapa(0);
    mapa = new Mapa();
    mapa->cargar_mapa(1);
    
    //Marcador
    puntos_actuales = 0;
    puntos_ganar = 800;
}

void EPantalla2::actualizar()
{
    render_fachada->actualizar();
    
    //Acciones de teclas (mover personaje)
    ultima_tecla = render_fachada->getPresionado();
    
    //Control del personaje
    digger->mover(ultima_tecla);
        
    bool perder = enemigo->mover(digger->animacion_sprite->get_global_bounds(), digger->animacion_sprite->get_posicion());
    bool perder2 = enemigo2->mover(digger->animacion_sprite->get_global_bounds(), digger->animacion_sprite->get_posicion());
    
    //Eliminar casillas
    puntos_actuales += mapa->eliminar_casilla(digger->animacion_sprite->get_posicion());
    
    //Actualizar HUD
    render_fachada->dibujarHUD(puntos_actuales, puntos_ganar);
    
    //Salida de emergencia
    if(ultima_tecla == Render_Fachada::Presionado::Salir)
    {
        jugando = false;
    }
    
    //Señal de victoria
    if(puntos_actuales >= puntos_ganar)
    {
        render_fachada->limpiar();
        jugando = false;
    }
    
    //Señal de derrota
    if(perder || perder2)
    {
        render_fachada->limpiar();
        Juego::instancia().reinicio = true;
        Juego::instancia().cambia_estado(EState::Estado_tipo::INTRO);
    }
}

void EPantalla2::dibujar(float dTime)
{
    //Interpolar posiciones
    digger->moverInterpolado(dTime);
    enemigo->moverInterpolado(dTime);
    enemigo2->moverInterpolado(dTime);
    
    //Dibujar
    render_fachada->dibujar(dTime);
}

void EPantalla2::limpiar()
{
    //Eliminar elementos creados
    delete digger;
    delete enemigo;
    delete enemigo2;
}