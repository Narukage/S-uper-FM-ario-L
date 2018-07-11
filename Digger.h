#ifndef DIGGER_H
#define DIGGER_H

#include "Render_Fachada.h"
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
    float velocidad_x = 230; //Velocidad del digger
    float velocidad_y = 230; //Velocidad del digger
    float sig_pos_x = 0;
    float sig_pos_y = 0;
    Animacion* animacion_sprite; //Clase animación para un manejo rápido
    
    void mover(Render_Fachada::Presionado);
    void moverInterpolado(float);
private:
};

#endif /* DIGGER_H */

