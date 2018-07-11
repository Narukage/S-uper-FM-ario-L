#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "Mario.h"

using namespace std;

class Camera {
public:
    Camera(sf::RenderWindow &window, Mario &mario);
    virtual ~Camera();
    
    void move(sf::RenderWindow &window, Mario &mario);
    void update(Mario &mario);
    
    sf::Text getText()      { return text;  };
    sf::Text getText2()     { return text2; };
    sf::Text getText3()     { return text3; };
    sf::Text getText4()     { return text4; };
    sf::Text getText5()     { return text5; };
    sf::Text getTextX()     { return textX; };
    sf::Text getFin()       { return fin;   };
    sf::Sprite getCoin()    { return coin;  };
    sf::View getCamara()    { return camara;};
        
private:
    sf::Vector2f position;
    sf::View camara;
    
    sf::Sprite coin;
    sf::Texture texture;
    
    sf::Text text;
    sf::Text text2;
    sf::Text text3;
    sf::Text text4;
    sf::Text text5;
    sf::Text textX;
    sf::Text fin;
    sf::Font font;

};

#endif /* CAMERA_H */

