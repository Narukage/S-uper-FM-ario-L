#ifndef MAP_H
#define MAP_H
#define WIDTH 800
#define HEIGHT 600

#endif /* MAP_H */
#include <iostream>
#include <SFML/Graphics.hpp>

class Map{
    private:

            enum Contenido{
                coco = 1,
                pared = -1,
                vacio = 0
            };

            Contenido contenido;

            Contenido mapa[WIDTH][HEIGHT];

    public:
        Map();
        int getWidth();
        int getHeight();
        Map getMap();
                
};

