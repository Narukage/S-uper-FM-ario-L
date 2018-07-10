
#ifndef EINTRO_H
#define EINTRO_H

#include "EState.h"
#include "Render_Fachada.h"
#include "Reloj.h"

#include "Juego.h"

class EIntro : public EState {
public:
    EIntro();
    EIntro(const EIntro& orig);
    virtual ~EIntro();
    
    //Patron singleton
    static EIntro& instancia(){
        static EIntro eintro;
        return eintro;
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
    
    int seleccionado; //Opcion del menú seleccionada
};

#endif /* EINTRO_H */

