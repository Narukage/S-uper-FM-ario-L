#ifndef RENDER_FACHADA_H
#define RENDER_FACHADA_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "Animacion.h"

class Render_Fachada {
public:
    
    //Teclas presionadas
    enum Presionado{
        none = 0,
        A = 1,
        D = 2,
        S = 3,
        W = 4,
        Space = 5,
        Salir = 6
    };
    
    //Constructores y destructores
    Render_Fachada();
    Render_Fachada(const Render_Fachada& orig);
    virtual ~Render_Fachada();
    static Render_Fachada& instancia(){
        static Render_Fachada render_fachada;
        return render_fachada;
    }
    
    //Funciones principales
    void inicializar(int, int, std::string, int, bool);
    void actualizar();
    void dibujar(float);
    
    //Teclado
    void actualizar_teclado(); //actualiza el ultimo boton presionado
    
    //Sprites y animaciones individuales
    
    //##########################################
    // GETTERS / SETTERS
    //##########################################
    Presionado getPresionado(){
        return presionado;
    }
private:
    
    Presionado presionado;       //Última tecla presionada
    
    sf::RenderWindow* ventana;   //Ventana principal del juego
    sf::Event evento;            //Evento principal del teclado
    std::vector<Animacion> sprites; //Lista de todos los sprites a pintar
};

#endif /* RENDER_FACHADA_H */

