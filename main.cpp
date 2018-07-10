#include <iostream>
#include "Juego.h"

using namespace std;

int main() {

    //Nuevo juego
    Juego *juego = new Juego();

    //correr juego
    juego->correr();
    
    delete juego;
    return 0;
}

