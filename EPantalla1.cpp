
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
}

void EPantalla1::actualizar()
{
    
}

void EPantalla1::dibujar(float dTime)
{
    render_fachada->dibujar(dTime);
}