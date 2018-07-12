
#include "Render_Fachada.h"
#include "Reloj.h"
#include "EState.h"
#include "EIntro.h"
#include "EPantalla1.h"
#include "EPantalla2.h"

#ifndef JUEGO_H
#define JUEGO_H

class Juego {
    
public:
    //Constructor
    Juego();
    Juego(const Juego& orig);
    
    //Destructor
    virtual ~Juego();
    
    //Instancia única
    static Juego& instancia(){
        static Juego juego;
        return juego;
    }
    
    //Corre el juego
    void correr();
    
    //Cambia estado del juego desde fuera
    void cambia_estado(EState::Estado_tipo);
    bool reinicio = false;
    
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
    EState* estado_actual; //Estado actual de juego
};

#endif /* JUEGO_H */

