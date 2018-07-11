#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <sstream>
#include "tinystr.h"
#include "tinyxml.h"
#include <string>


using namespace std;

class Map {
    
public:
    
    Map();
    void drawTile(sf::RenderWindow &window);
    virtual ~Map();
    
    sf::Sprite getSprite()          { return sprite;            };
    sf::Sprite getSprite2()         { return sprite2;           };
    sf::Sprite getSprite3()         { return sprite3;           };
    sf::Sprite getCascada1()        { return cascada;           };
    sf::Sprite getCaja()            { return caja;              };
    sf::Sprite getCaja2()           { return caja2;             };
    sf::Sprite getTubo()            { return tubo;              };
    sf::Sprite**** getTileMap()     { return _tilemapSprite;    };
    int getWidth()                  { return _width;            };
    int getHeight()                 { return _height;           };
    
private:
    //Tilemap
        int _width;
        int _tilewidth;
        sf::Clock reloj;
        
        int ***_tilemap;
        int _numlayers;
        int _height;
        int _tileheigth;
    
        sf::Sprite ****_tilemapSprite;
        sf::Sprite *_tilesetSprite;
        
        sf::Sprite sprite;
        sf::Sprite sprite2;
        sf::Sprite tubo;
        sf::Sprite sprite3;
        sf::Sprite cascada;
        sf::Sprite caja;
        sf::Sprite caja2;
        sf::Texture textura4;
        sf::Texture textura;
        sf::Texture textura2;
        sf::Texture textura3;
    
        sf::Texture _tilesetTexture;
        
        

};
