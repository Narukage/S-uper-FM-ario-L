#ifndef MAP_H
#define MAP_H
#endif /* MAP_H */

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
            sf::Sprite sprite;
            int map[10][10] = {
                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},     //1 = pared
                       {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},     //0 = vacio
                       {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
                       {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
                       {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
                       {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
                       {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
                       {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
                       {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
                   };
        
        
            int cocos;
            sf::Sprite pared;

    public:
        Map();
        ~Map();
        void printMap(sf::RenderWindow& window);
        bool ocupada(int posx, int posy);
        int getTotalCocos();
        
        const sf::Sprite &getSprite() const;
        
        //GETTERS && SETTERS
        int getWidth()  { return WIDTH;  };
        int getHeight() { return HEIGHT; };
            
};

