
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

                if(evento.key.code==sf::Keyboard::Q){
                    presionado = Salir;
                }
                break;
        }
    }
}

//##########################################
//PINTADO
//##########################################
void Render_Fachada::dibujar(float dTime)
{
    ventana->clear(sf::Color::Black);
    
    ventana->display();
}