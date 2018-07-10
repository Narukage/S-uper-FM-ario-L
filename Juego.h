
#include "Render_Fachada.h"
#include "Reloj.h"

#ifndef JUEGO_H
#define JUEGO_H

class Juego {
    
public:
    //Constructor
    Juego();
    Juego(const Juego& orig);
    
    //Destructor
    virtual ~Juego();
    
    //Corre el juego
    void correr();
    
private:
    void inicializar();
    void actualizar();
    void dibujar(float d_time);
    void limpiar();
    
    //##########################################
    //Variables privadas
    //##########################################    
    //Variables del sistema
    Render_Fachada* render_fachada;          //Dibuja_todo
    Render_Fachada::Presionado ultima_tecla; //Ultima teclada presionada
    Reloj reloj;                             //Reloj del sistema
    
    bool jugando; //Frena el juego u (ventanas y eventos)na vez se acaba o se cierra la ventana
    
};

#endif /* JUEGO_H */

