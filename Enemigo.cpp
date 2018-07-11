#include "Enemigo.h"

Enemigo::Enemigo() {
}

Enemigo::Enemigo(const Enemigo& orig) {
}

Enemigo::~Enemigo() {
    
}

void Enemigo::mover(Render_Fachada::Presionado p)
{
    if(p == Render_Fachada::Presionado::W)
    {
        animacion_sprite->set_rotacion(0);
        sig_pos_x = 0;
        sig_pos_y = -1;
    }
    
    if(p == Render_Fachada::Presionado::S)
    {
        animacion_sprite->set_rotacion(180);
        sig_pos_x = 0;
        sig_pos_y = 1;
    }
    
    if(p == Render_Fachada::Presionado::A)
    {
        animacion_sprite->set_rotacion(270);
        sig_pos_x = -1;
        sig_pos_y = 0;
    }
    
    if(p == Render_Fachada::Presionado::D)
    {
        animacion_sprite->set_rotacion(90);
        sig_pos_x = 1;
        sig_pos_y = 0;
    }
    
    if(p == Render_Fachada::Presionado::none)
    {
        sig_pos_x = 0;
        sig_pos_y = 0;
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
}

void Enemigo::moverInterpolado(float dTime)
{
    animacion_sprite->move(sig_pos_x * velocidad_x * dTime, sig_pos_y * velocidad_y * dTime);
}