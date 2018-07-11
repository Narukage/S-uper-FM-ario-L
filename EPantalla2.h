
#ifndef EPANTALLA2_H
#define EPANTALLA2_H

#include "EState.h"
#include "Render_Fachada.h"
#include "Digger.h"
#include "Mapa.h"

class EPantalla2 : public EState{
public:
    EPantalla2();
    EPantalla2(const EPantalla2& orig);
    virtual ~EPantalla2();
    
    //Patron singleton
    static EPantalla2& instancia(){
        static EPantalla2 epantalla2;
        return epantalla2;
    }
    
    //##########################################
    //PRINCIPALES
    //##########################################
    virtual void inicializar();
    virtual void actualizar();
    virtual void dibujar(float dTime);
    void limpiar();
    
private:
    //##########################################
    //Variables privadas
    //##########################################    
    //Variables del sistema
    Render_Fachada* render_fachada;          //Dibuja_todo
    Render_Fachada::Presionado ultima_tecla; //Ultima teclada presionada
    
    //Elementos del mapa
    Digger* digger;
    Mapa* mapa;
    int puntos_ganar; //Puntos para ganar
    int puntos_actuales; //Puntos actuales
};

#endif /* EPANTALLA2_H */

