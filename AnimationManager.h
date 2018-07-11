#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H
#include "IFachada.h"

//SINGLETON

class AnimationManager {
private:
    //IFachada* motor;
    static AnimationManager* pinstance;
    
public:
    static AnimationManager* Instance(int libreria);
    //IFachada* getMotor(){ return motor; };
    ~AnimationManager();
    
    //=================================
    // ANIMACIONES
    //=================================
    int crearAnimacion(std::string url, float imageCountx, float imageCounty, float switchTime, int filas, int columnas);
    void updateAnimacion(int id, int row,float deltaTime);
    void dibujarAnimacion(int id, float positionx, float positiony, float scale, sf::RenderWindow &window);
    bool borrarAnimacion(int id);
    
protected:
    AnimationManager(int libreria);
    AnimationManager(const AnimationManager& orig);
    
private:
    struct Animacion{
        int id;
        sf::Vector2u imageCount;
        float switchTime;
        sf::IntRect uvRect;
        sf::Vector2u currentImage;
        float totalTime;
        sf::Vector2u textureSize;
        sf::Texture* textura;
        sf::Sprite* sprite;
    };
    
    std::vector<Animacion> animaciones;
    int cont = 0;
    int cont2 = 0;
    int cont3 = 0;
    int cont4 = 0; 

};

#endif /* RENDERMANAGER_H */
