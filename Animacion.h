
#ifndef ANIMACION_H
#define ANIMACION_H

#include <SFML/Graphics.hpp>

class Animacion {
public:
    
    //Constructores y destructores
    Animacion();
    Animacion(const Animacion& orig);
    virtual ~Animacion();
    
    //Funciones principales
    void inicializar(int, const char*, sf::IntRect*, sf::Vector2i*, int, int, bool);
    
    //Transformaciones
    void set_posicion(float, float);
    void set_origen(int, int, int);
    void set_rotacion(float);
    void set_tamanyo(float, float);
    
    //Cambia y recoge datos
    void set_color(sf::Color);
    void set_velocidad(int);
    sf::Sprite get_frame_actual(float);
    sf::Vector2f get_posicion();
    int get_id();
    
private:

    //Visuales
    sf::Texture textura;    //textura de los sprites
    sf::Sprite* frames;     //Frame de cada animación
    sf::Color color;        //Color de la textura

    //Numéricos
    float velocidad_frames; //Duracion de cada frame
    int num_frames;         //Número de frames de la animación
    bool bucle;             //Si se repite en bucle o no
    float hasta_next_frame; //tiempo que falta hasta el siguiente frame
    
    //Estado
    int frame_actual;       //Indica el frame actual a pintar
    int id;                 //Identificador de la animación
};

#endif /* ANIMACION_H */

