
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
    render_fachada->inicializar(800, 600, "Digger", 60, true);
    
    //Inicializar variables
    jugando = true;
    seleccionado = 0;
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
        if(seleccionado>1){
            seleccionado = 0;
        }
        std::cout<<"hola holita222   a  "<<seleccionado<<std::endl;
    }
    if(ultima_tecla == Render_Fachada::Presionado::S)
    {
        seleccionado--;
        if(seleccionado<0){
            seleccionado = 1;
        }
        std::cout<<"hola holita "<<seleccionado<<std::endl;
    }
    if(ultima_tecla == Render_Fachada::Presionado::Intro)
    {
        if(seleccionado == 1)
        {
            jugando = false;
        }
        
        if(seleccionado == 0)
        {
        std::cout<<"SSSSSSSSSSSSSSs "<<seleccionado<<std::endl;
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