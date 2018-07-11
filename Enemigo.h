#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Render_Fachada.h"
#include "Animacion.h"
class Enemigo {
public:
    Enemigo();
    Enemigo(const Enemigo& orig);
    virtual ~Enemigo();
    
    //Variables del personaje
    int animacion; //id de la animacion
    int puntos = 0; //puntos, al empezar son 0
    float velocidad_x = 250; //Velocidad del digger
    float velocidad_y = 250; //Velocidad del digger
    float sig_pos_x = 0;
    float sig_pos_y = 0;
    Animacion* animacion_sprite; //Clase animación para un manejo rápido
    
    void mover(Render_Fachada::Presionado);
    void moverInterpolado(float);
    
private:

};

#endif /* ENEMIGO_H */
