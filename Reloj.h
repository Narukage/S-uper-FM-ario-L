#include <SFML/Graphics.hpp>

#ifndef RELOJ_H
#define RELOJ_H

class Reloj {
public:
    //##########################################
    //CONSUTRCTORES & DESTRUCTORES
    //##########################################
    Reloj();
    Reloj(const Reloj& orig);
    virtual ~Reloj();
    
    //##########################################
    //CONSUTRCTORES & DESTRUCTORES
    //##########################################
    float tiempoTranscurrido();
    
private:

    sf::Clock reloj;
};

#endif /* RELOJ_H */

