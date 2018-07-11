#ifndef IFACHADA_H
#define IFACHADA_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

//FACHADA

class IFachada {
public:
    IFachada(){};
    virtual ~IFachada(){};
    virtual int crearAnimacion(std::string url, float imageCountx, float imageCounty, float switchTime, int filas, int columnas) = 0;
    virtual void updateAnimacion(int id, int row,float deltaTime) = 0;
    virtual void dibujarAnimacion(int id, float positionx, float positiony, float scale, sf::RenderWindow &window) = 0;
    virtual bool borrarAnimacion(int id) = 0;
private:

};

#endif /* IFACHADA_H */
