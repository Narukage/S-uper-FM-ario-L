
//Includes de C++ o similar
#include <iostream>

//Includes del proyecto
#include "Render_Fachada.h"

//##########################################
//CONSUTRCTORES & DESTRUCTORES
//##########################################
Render_Fachada::Render_Fachada() {
}

Render_Fachada::Render_Fachada(const Render_Fachada& orig) {
}

Render_Fachada::~Render_Fachada() {
    //Cerrar todo 
    if(ventana)
        ventana->close();

    //Delete pointers
    delete ventana;
}

//##########################################
// PRINCIPALES
//##########################################
void Render_Fachada::inicializar(int ancho, int alto, std::string nombre_ventana, int tasa_frames, bool v_sync)
{
    //Crear ventana
    ventana = new sf::RenderWindow(sf::VideoMode(ancho,alto), nombre_ventana);
    
    //Variables de SFML para opciones de ventana
    ventana->setFramerateLimit(tasa_frames);
    ventana->setVerticalSyncEnabled(v_sync);
    
    //Inicializaciones de variables
    animacion_id = 0;
    sprite_id = 0;
}

//Actualizar la fachada
void Render_Fachada::actualizar()
{
    actualizar_teclado();
}

//##########################################
//TECLADO
//##########################################

//Actualizar el teclado (es inevitable porque van acoplados el sistema de eventos de teclado con el de dibujado por la ventana)
void Render_Fachada::actualizar_teclado()
{
    while(ventana->pollEvent(evento)){
        switch(evento.type){
            case sf::Event::KeyPressed:
                if(evento.key.code==sf::Keyboard::A){
                    presionado = A;
                }else

                if(evento.key.code==sf::Keyboard::D){
                    presionado = D;
                }else

                if(evento.key.code==sf::Keyboard::S){
                    presionado = S;
                }else

                if(evento.key.code==sf::Keyboard::W){
                    presionado = W;
                }else

                if(evento.key.code==sf::Keyboard::Space){
                    presionado = Space;
                }else

                if(evento.key.code==sf::Keyboard::Escape){
                    presionado = Salir;
                }else

                if(evento.key.code==sf::Keyboard::Enter){
                    presionado = Intro;
                }
                break;
                
            case sf::Event::KeyReleased:
                presionado = none;
                break;
        }
    }
}

//##########################################
//PINTADO
//##########################################
void Render_Fachada::dibujar(float dTime)
{
    //Limpiar ventana
    ventana->clear(sf::Color::Black);
    
    //Pintar sprites del mapa
    for(int i = 0; i < mapa.size(); i++)
    {
        ventana->draw(mapa[i]->get_sprite());
    }
    
    //Pintar animaciones
    for(int i = 0; i < animaciones.size(); i++)
    {
        ventana->draw(animaciones[i]->get_frame_actual(dTime));
    }
    
    //Mostrar en ventana lo grabado en el buffer
    ventana->display();
}

int Render_Fachada::Anyadir_animacion(const char* fichero, sf::IntRect* coordenadas, sf::Vector2i* origenes, int num_fotogramas, int frames_por_segundo = 60, bool en_bucle = true)
{
    //Creamos la animacion
    Animacion* a = new Animacion();
    a->inicializar(animacion_id, fichero, coordenadas, origenes, num_fotogramas, frames_por_segundo, en_bucle);
    
    //Metemos en la lista
    animaciones.push_back(a);
    
    //Corremos las id's un sitio
    animacion_id++;
    
    return (animacion_id -1);
}

int Render_Fachada::Anyadir_sprite(const char* fichero, sf::IntRect coordenadas, sf::Vector2i origen)
{
    //Creamos la animacion
    Sprite* a = new Sprite();
    a->inicializar(sprite_id, fichero, coordenadas, origen);
    
    //Metemos en la lista
    mapa.push_back(a);
    
    //Corremos las id's un sitio
    sprite_id++;
    
    return (sprite_id -1);
}

void Render_Fachada::Mover_animacion(int id, float x, float y)
{
    for(int i = 0; i < animaciones.size(); i++)
    {
        if(animaciones[i]->get_id() == id)
            animaciones[i]->set_posicion(x, y);
    }
}

void Render_Fachada::Mover_sprite(int id, float x, float y)
{
    for(int i = 0; i < mapa.size(); i++)
    {
        if(mapa[i]->get_id() == id)
            mapa[i]->set_posicion(x, y);
    }
}
