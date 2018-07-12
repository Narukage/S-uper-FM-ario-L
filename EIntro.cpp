
#include "EIntro.h"
#include <iostream>

//##########################################
//CONSTRUCTORES & DESTRUCTORES
//##########################################
EIntro::EIntro() {
}

EIntro::EIntro(const EIntro& orig) {
}

EIntro::~EIntro() {
} 

//##########################################
//PRINCIPALES
//##########################################
void EIntro::inicializar()
{
    //Inicializar el dibuja todo
    render_fachada = &Render_Fachada::instancia();
    if(!Juego::instancia().reinicio)
    {
        render_fachada->inicializar(800, 600, "Digger", 60, true);
    }
    
    //Inicializar variables
    jugando = true;
    seleccionado = 0;
    
    //Menú
    int id = render_fachada->Anyadir_sprite("assets/sprites/pared.png", sf::IntRect(0,0,16,16), sf::Vector2i(25,25));
    selector = render_fachada->Devolver_sprite(id);
    selector->set_tamanyo(50.0f/16.0f, 50.0f/16.0f);
    selector->set_posicion(270,200);
    
     id = render_fachada->Anyadir_sprite("assets/sprites/botonplay.png", sf::IntRect(0,0,200,50), sf::Vector2i(0,0));
    seleccion1 = render_fachada->Devolver_sprite(id);
  //  seleccion1->set_tamanyo(50.0f/16.0f, 50.0f/16.0f);
    seleccion1->set_posicion(280, 125);
    
     id = render_fachada->Anyadir_sprite("assets/sprites/botonexit.png", sf::IntRect(0,0,200,50), sf::Vector2i(0,0));
    seleccion2 = render_fachada->Devolver_sprite(id);
   // seleccion2->set_tamanyo(50.0f/16.0f, 50.0f/16.0f);
    seleccion2->set_posicion(280, 225);
}

void EIntro::actualizar()
{
    //Actualizar fachadas
    render_fachada->actualizar();
    
    //Acciones de teclas (cerrar juego)
    ultima_tecla = render_fachada->getPresionado();
    
    //Control del menú
    if(ultima_tecla == Render_Fachada::Presionado::W)
    {
        seleccionado++;
        selector->set_posicion(270,300);
        if(seleccionado>1){
            seleccionado = 0;
            selector->set_posicion(270,200);
        }
    }
    if(ultima_tecla == Render_Fachada::Presionado::S)
    {
        seleccionado--;
        selector->set_posicion(270,200);
        if(seleccionado<0){
            seleccionado = 1;
            selector->set_posicion(270,300);
        }
    }
    if(ultima_tecla == Render_Fachada::Presionado::Intro)
    {
        if(seleccionado == 1)
        {
            jugando = false;
        }
        
        if(seleccionado == 0)
        {
            render_fachada->Borrar_sprite(selector->get_id());
            render_fachada->Borrar_sprite(seleccion1->get_id());
            render_fachada->Borrar_sprite(seleccion2->get_id());
            Juego::instancia().cambia_estado(EState::Estado_tipo::PANTALLA1);
        }
    }
    
    //Salida de emergencia
    if(ultima_tecla == Render_Fachada::Presionado::Salir)
    {
        jugando = false;
    }
}

void EIntro::dibujar(float dTime)
{
    render_fachada->dibujar(dTime);
}