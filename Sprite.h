#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>

class Sprite {
public:
    Sprite();
    Sprite(const Sprite& orig);
    virtual ~Sprite();
    
    //Funciones principales
    void inicializar(int, const char*, sf::IntRect, sf::Vector2i);
    
    //Transformaciones
    void set_posicion(float, float);
    void set_origen(int, int);
    void set_rotacion(float);
    void set_tamanyo(float, float);
    void move(float, float);
    
    //Cambia y recoge datos
    void set_color(sf::Color);
    sf::Sprite get_sprite();
    sf::Vector2f get_posicion();
    int get_id();
    
private:

    //Visuales
    sf::Texture textura;    //textura de los sprites
    sf::Sprite sprite;      //Frame de cada animación
    sf::Color color;        //Color de la textura

    //Numéricos
    int id;                 //Identificador de la animación
};

#endif /* SPRITE_H */

