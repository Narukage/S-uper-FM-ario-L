#include "Enemigo.h"

Enemigo::Enemigo() {
}

Enemigo::Enemigo(const Enemigo& orig) {
}

Enemigo::~Enemigo() {
    
}

bool Enemigo::mover(sf::FloatRect dig, sf::Vector2f pos)
{
    bool return_colision = false;
    
    if(pos.y <= animacion_sprite->get_posicion().y)
    {
        animacion_sprite->set_rotacion(0);
        sig_pos_y = -1;
    }
    
    if(pos.y > animacion_sprite->get_posicion().y)
    {
        animacion_sprite->set_rotacion(180);
        sig_pos_y = 1;
    }
    
    if(pos.x <= animacion_sprite->get_posicion().x)
    {
        animacion_sprite->set_rotacion(270);
        sig_pos_x = -1;
    }
    
    if(pos.x > animacion_sprite->get_posicion().x)
    {
        animacion_sprite->set_rotacion(90);
        sig_pos_x = 1;
    }
    
    //Comprobar colisión
    sf::Vector2f colision = animacion_sprite->get_posicion() + sf::Vector2f(sig_pos_x, sig_pos_y);
    if(colision.x <= 26.0f && sig_pos_x < 0)
    {
        sig_pos_x = 0;
    }
    if(colision.x >= 800.0f - 26.0f && sig_pos_x > 0)
    {
        sig_pos_x = 0;
    }
    if(colision.y <= 26.0f && sig_pos_y < 0)
    {
        sig_pos_y = 0;
    }
    if(colision.y >= 600.0f - 26.0f && sig_pos_y > 0)
    {
        sig_pos_y = 0;
    }
    
    //Colision con personaje
    if(dig.intersects(animacion_sprite->get_global_bounds())){
        return_colision = true;
    }
    
    return return_colision;
}

void Enemigo::moverInterpolado(float dTime)
{
    animacion_sprite->move(sig_pos_x * velocidad_x * dTime, sig_pos_y * velocidad_y * dTime);
}