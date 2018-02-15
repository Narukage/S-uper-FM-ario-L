#ifndef GHOST_H
#define GHOST_H
#endif /* GHOST_H */

#include <iostream>
#include <SFML/Graphics.hpp>

class Ghost{
private:
    bool alive;
    float playerSpeed;
    sf::Vector2f current_pos;
    sf::Vector2f dir_move;
    sf::Sprite misprite;
    sf::Texture textura;
    bool paused;
    
public:
    Ghost();
    ~Ghost();
    /*void pause(); //stop ghost animation
    void resume(); //resume ghost animation
    void restart(); //reinicia su posicion en el mapa
    void kill();
    bool isAlive();
    void updatePos(); //ghost movement
    void interpolate(float d_time);    //ghost render interpolation
    sf::Vector2f getCurrentPosition();
    sf::Sprite getSprite();*/
};

