#ifndef DIGGER_H
#define DIGGER_H

#include "Animacion.h"
class Digger {
public:
    Digger();
    Digger(const Digger& orig);
    virtual ~Digger();
    
    //Variables del personaje
    int vidas = 4;
    int animacion; //id de la animacion
    int puntos = 0; //puntos, al empezar son 0
    
private:
};

#endif /* DIGGER_H */

