#ifndef EPANTALLA1_H
#define EPANTALLA1_H

#include "EState.h"

class EPantalla1 : public EState {
public:
    EPantalla1();
    EPantalla1(const EPantalla1& orig);
    virtual ~EPantalla1();
    
    //Patron singleton
    static EPantalla1& instancia(){
        static EPantalla1 epantalla1;
        return epantalla1;
    }
    
    //##########################################
    //PRINCIPALES
    //##########################################
    virtual void inicializar();
    virtual void actualizar();
    virtual void dibujar(float dTime);
    
private:
    //##########################################
    //Variables privadas
    //##########################################    
    //Variables del sistema
    Render_Fachada* render_fachada;          //Dibuja_todo
    Render_Fachada::Presionado ultima_tecla; //Ultima teclada presionada
    
};

#endif /* EPANTALLA1_H */
