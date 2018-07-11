#ifndef MAPA_H
#define MAPA_H

#include "Casilla.h"
#include "Render_Fachada.h"

class Mapa {
public:
    Mapa();
    Mapa(const Mapa& orig);
    virtual ~Mapa();
    
    //Carga toda la información del mapa según el tipo
    void cargar_mapa(int);
    float eliminar_casilla(sf::Vector2f pos);
    
    //Variables de la escena
    int tamanyo_x;
    int tamanyo_y;
    Casilla*** casillas;
    
private:

};

#endif /* MAPA_H */

