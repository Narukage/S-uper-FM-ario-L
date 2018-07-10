
#ifndef EPANTALLA2_H
#define EPANTALLA2_H

#include "EState.h"

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
    
private:

};

#endif /* EPANTALLA2_H */

