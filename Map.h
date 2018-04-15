#pragma once
#define WIDTH 10
#define HEIGHT 10
#define SIZE 12

#include <iostream>
#include <SFML/Graphics.hpp>

class Map{
    private:
            
            //array de punteros a punteros a array
           //int **mapa = new int* [SIZE];
           sf::Texture textura;
           sf::CircleShape coco;
           sf::CircleShape interseccion;
           sf::Sprite sprite;
            int map[11][12] = {
                       {1,1,1,1,1,1,1,1,2,1,1,1}, //1 pared
                       {1,0,2,2,2,2,2,1,2,1,2,1}, //2 coco
                       {1,2,1,1,2,1,2,1,2,1,2,1}, //0 vacio
                       {1,2,2,1,2,1,2,2,3,1,2,1}, //3 coco gordo
                       {1,2,2,1,2,1,1,1,2,1,2,1},
                       {1,2,2,2,2,2,2,1,2,2,3,1},
                       {1,2,2,1,2,1,1,1,2,1,2,1},
                       {1,2,2,1,2,1,2,2,2,1,2,1},
                       {1,2,1,1,2,1,2,1,2,1,2,1},
                       {1,3,2,2,2,2,2,1,2,1,2,1},
                       {1,1,1,1,1,1,1,1,2,1,1,1}

                   };
            
            int intersect[11][12] = {
                       {0,0,0,0,0,0,0,0,0,0,0,0}, //1 interseccion
                       {0,1,0,0,1,0,0,0,0,0,1,0}, //0 no interseccion
                       {0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,1,0,0,0,1,0,1,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,1,1,0,1,0,0,0,1,0,1,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,1,0,0,0,1,0,1,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,1,0,0,1,0,0,0,0,0,1,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0}
            };
        
            int cocos;
            sf::Sprite pared;


    public:
        Map();
        ~Map();
        void printMap(sf::RenderWindow& window);
        bool ocupada(int posx, int posy);
        bool intersecta(int posx, int posy);
        bool hayCoco(int posx, int posy);
        bool hayCocoGordo(int posx, int posy);
        
        const sf::Sprite &getSprite() const;
        
        //GETTERS && SETTERS
        int getWidth()  { return WIDTH;  };
        int getHeight() { return HEIGHT; };
        int getTotalCocos() { return cocos; };
            
};

