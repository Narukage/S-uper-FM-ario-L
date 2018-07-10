#include <iostream>
#include "Juego.h"

using namespace std;

int main() {

    //Nuevo juego
    Juego* juego = &Juego::instancia();

    //correr juego
    juego->correr();
    
    return 0;
}

