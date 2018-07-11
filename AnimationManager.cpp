#include "AnimationManager.h"

//SINGLETON

AnimationManager* AnimationManager::pinstance = 0;
    
AnimationManager* AnimationManager::Instance(int libreria){
    if(pinstance==0){
        pinstance = new AnimationManager(libreria);
    }
    return pinstance;
}

AnimationManager::AnimationManager(int libreria) {

}

AnimationManager *r1 = AnimationManager::Instance(1);
AnimationManager *r2 = r1->Instance(1);
AnimationManager &refr = * AnimationManager::Instance(1);


int AnimationManager::crearAnimacion(std::string url, float imageCountx, float imageCounty, float switchTime, int filas, int columnas){
    Animacion a;
    a.textura = new sf::Texture;
    if(!a.textura->loadFromFile(url)){
        //std::cout << "Error al cargar la textura." << std::endl;
        exit(-1);
    }
    
    a.sprite = new sf::Sprite;
    
    a.sprite->setTexture(*(a.textura));
    
    a.textureSize = (*a.textura).getSize();
    a.textureSize.x = (a.textureSize.x / a.textureSize.x) * columnas;
    a.textureSize.y = (a.textureSize.y / a.textureSize.y) * filas;
    
    a.imageCount.x = imageCountx;
    a.imageCount.y = imageCounty;
    a.switchTime = switchTime;
    a.totalTime = 0.0f;
    a.currentImage.x = 0;
    
    a.uvRect.width = a.textura->getSize().x / float(a.imageCount.x);
    a.uvRect.height = a.textura->getSize().y / float(a.imageCount.y);
    
    a.id = cont2;
    cont2++;
    
    animaciones.push_back(a);
    
    return a.id;
}

void AnimationManager::updateAnimacion(int id, int row,float deltaTime){
    for(unsigned int i = 0; i < animaciones.size(); i++){
        if(animaciones[i].id==id){
            animaciones[i].currentImage.y = row;
            animaciones[i].totalTime += deltaTime;

            //Si se ha sobrepasado el tiempo de un frame, se pasa al siguiente
            if(animaciones[i].totalTime >= animaciones[i].switchTime){
            animaciones[i].totalTime -= animaciones[i].switchTime;
                animaciones[i].currentImage.x++;
                
                //Si llega al final del array de sprites de la animación, vuelve al principio
                if(animaciones[i].currentImage.x >= animaciones[i].imageCount.x){
                    animaciones[i].currentImage.x = 0;
                }
            }
            
            //Se coloca el recuadro sobre el sprite indicado
            animaciones[i].uvRect.left = animaciones[i].currentImage.x * animaciones[i].uvRect.width;
            animaciones[i].uvRect.top = animaciones[i].currentImage.y * animaciones[i].uvRect.height;

            //Se coloca sobre el sprite de la animación la textura del nuevo recuadro
            animaciones[i].sprite->setTextureRect(animaciones[i].uvRect);
        }
    }
}

void AnimationManager::dibujarAnimacion(int id, float positionx, float positiony, float scale, sf::RenderWindow &window){
    for(unsigned int i = 0; i < animaciones.size(); i++){
        if(animaciones[i].id==id){
            //Posicionar y escalar
            animaciones[i].sprite->setPosition(positionx, positiony);
            animaciones[i].sprite->setScale(scale, scale);
            
            //Dibujar sprite indicado
            window.draw(*(animaciones[i].sprite));
       }
    }
}

bool AnimationManager::borrarAnimacion(int id){
    for(unsigned int i = 0; i < animaciones.size(); i++){
        if(animaciones[i].id==id){
            Animacion aux = animaciones[i];
            animaciones.erase(animaciones.begin()+i);
            delete aux.sprite;
            delete aux.textura;
            delete &aux;
            return true;
        }
    }
    return false;
}