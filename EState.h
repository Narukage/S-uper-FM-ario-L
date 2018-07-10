#ifndef ESTATE_H
#define ESTATE_H

class EState {
public:
    
    enum Estado_tipo{
        INTRO,
        PANTALLA1,
        PANTALLA2
    };
    
    EState();
    EState(const EState& orig);
    virtual ~EState();
    
    virtual void inicializar() = 0;
    virtual void actualizar() = 0;
    virtual void dibujar(float dTime) = 0;
    
    bool jugando; //Frena el juego u (ventanas y eventos)na vez se acaba o se cierra la ventana
private:

};

#endif /* ESTATE_H */

