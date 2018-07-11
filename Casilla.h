#ifndef CASILLA_H
#define CASILLA_H

#include "Sprite.h"

class Casilla {
public:
    Casilla();
    Casilla(const Casilla& orig);
    virtual ~Casilla();
    
    int puntos; //Si la casilla otorga puntos al ser construida
    Sprite* sprite; //Sprite de la casilla en sí
    bool activada;  //Si la casilla ha sido consumida o no
    
private:

};

#endif /* CASILLA_H */

