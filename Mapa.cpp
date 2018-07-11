#include "Mapa.h"
#include "Sprite.h"

#include <iostream>
Mapa::Mapa() {
}

Mapa::Mapa(const Mapa& orig) {
}

Mapa::~Mapa() {
    delete [] casillas;
    delete casillas;
}

void Mapa::cargar_mapa(int tipo)
{
    
    tamanyo_x = 800/50;
    tamanyo_y = 600/50;
        
    if(tipo == 0)
    {
        casillas = new Casilla**[tamanyo_x];
        for(int i = 0; i < tamanyo_x; i++)
        {
            casillas[i] = new Casilla*[tamanyo_y];
            for(int j = 0; j < tamanyo_y; j++){
                casillas[i][j] = new Casilla();
                casillas[i][j]->activada = true;
                casillas[i][j]->puntos = 10;
                Render_Fachada* render = &Render_Fachada::instancia();
                int id = render->Anyadir_sprite("assets/sprites/pared.png", sf::IntRect(0,0,16,16), sf::Vector2i(25,25));
                casillas[i][j]->sprite = render->Devolver_sprite(id);
                casillas[i][j]->sprite->set_tamanyo(50.0f/16.0f, 50.0f/16.0f);
                casillas[i][j]->sprite->set_posicion(75+i*50,75+j*50);
                
            }
        }
    }
    
    if(tipo == 1)
    {
        casillas = new Casilla**[tamanyo_x];
        for(int i = 0; i < tamanyo_x; i++)
        {
            casillas[i] = new Casilla*[tamanyo_y];
            for(int j = 0; j < tamanyo_y; j++){
                casillas[i][j] = new Casilla();
                casillas[i][j]->activada = true;
                casillas[i][j]->puntos = 15;
                Render_Fachada* render = &Render_Fachada::instancia();
                int id = render->Anyadir_sprite("assets/sprites/pared2.png", sf::IntRect(0,0,16,16), sf::Vector2i(25,25));
                casillas[i][j]->sprite = render->Devolver_sprite(id);
                casillas[i][j]->sprite->set_tamanyo(50.0f/16.0f, 50.0f/16.0f);
                casillas[i][j]->sprite->set_posicion(75+i*50,75+j*50);
                
            }
        }
    }
}

float Mapa::eliminar_casilla(sf::Vector2f pos)
{
    float return_points = 0;
    
    int pos_x = ((int) pos.x)/50;
    int pos_y = ((int) pos.y)/50;
    
    Render_Fachada* render = &Render_Fachada::instancia();
    if(casillas[pos_x][pos_y]->activada ){
        render->Borrar_sprite(casillas[pos_x][pos_y]->sprite->get_id());
        casillas[pos_x][pos_y]->activada = false;
        return_points = casillas[pos_x][pos_y]->puntos;
    }

    return return_points;
}