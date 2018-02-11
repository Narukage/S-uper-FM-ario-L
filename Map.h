#ifndef MAP_H
#define MAP_H
#define WIDTH 10
#define HEIGHT 10

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

            Contenido[WIDTH][HEIGHT] mapa = {
                
                        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                        {-1, 1, 1, 1, 1, 1, 1, 1, 1,-1},
                        {-1, 0, 0,-1, 0, 0,-1, 0, 0,-1},
                        {-1, 0, 0,-1, 0, 0,-1, 0, 0,-1},
                        {-1, 0, 0,-1, 0, 0,-1, 0, 0,-1},
                        {-1, 0, 0,-1, 0, 0,-1, 0, 0,-1},
                        {-1, 0, 0,-1, 0, 0,-1, 0, 0,-1},
                        {-1, 0, 0,-1, 0, 0,-1, 0, 0,-1},
                        {-1, 1, 1, 1, 1, 1, 1, 1, 1,-1},
                        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
    };
            
            //Contenido[10][10] mapa = {1,2,3,4,5};
            int cocos;

    public:
        Map();
        int getWidth();
        int getHeight();
        Map getMap();
        int getTotalCocos();
                
};

