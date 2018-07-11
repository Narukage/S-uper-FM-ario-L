#include "Camera.h"
#include "Mario.h"

Camera::Camera(sf::RenderWindow &window, Mario &mario) {
    sf::View camera(sf::FloatRect(0, 70, 400, 200));
    camera.setSize(400, 300);
    window.setView(camera);
    camara = camera;
    
    if(!font.loadFromFile("assets/fonts/prstart.ttf")){
        std::cout << "Fuente no aplicada" <<std::endl;
    }
    
    if(!texture.loadFromFile("assets/sprites/coin.png")){
        std::cout << "Error al cargar la textura" << std::endl;
    }
    
    coin.setTexture(texture);
    coin.setPosition(230,28);
    coin.setScale(0.02, 0.02);
        
    text.setColor(sf::Color::White);
    text.setFont(font);
    
    text.setString("MARIO X ");
    text.setPosition(10, 30);
    text.setScale(0.3, 0.3);
    
    text2 = text;
    std::stringstream ss;
    ss << mario.getLifes();
    text2.setString(ss.str().c_str());
    text2.setPosition(90, 30);
    
    text3 = text;
    std::stringstream ss2;
    ss2 << mario.getScore();
    text3.setString(ss2.str().c_str());
    text3.setPosition(150, 30);
    
    text4 = text;
    std::stringstream ss3;
    ss3 << mario.getCoins();
    text4.setString(ss3.str().c_str());
    text4.setPosition(270, 30);
    
    text5 = text;
    text5.setString("LEVEL 1");
    text5.setPosition(325, 30);
    
    textX = text;
    textX.setString("X");
    textX.setPosition(250, 30);
    
    fin = text;
    fin.setString("GAME OVER");
    fin.setPosition(camara.getCenter().x, camara.getCenter().y);
 
}

Camera::~Camera() {
    
}

void Camera::update(Mario &mario){
    text2 = text;
    std::stringstream ss;
    ss << mario.getLifes();
    text2.setString(ss.str().c_str());
    
    text3 = text;
    std::stringstream ss2;
    ss2 << mario.getScore();
    text3.setString(ss2.str().c_str());
    
    text4 = text;
    std::stringstream ss3;
    ss3 << mario.getCoins();
    text4.setString(ss3.str().c_str());
}

void Camera::move(sf::RenderWindow &window, Mario &mario){

    if(mario.getX() > 1000){
        camara.setCenter(1050, 170);
    }else{
        if(mario.getX() < 200){
            camara.setCenter(200, 170);
        }else{
            camara.setCenter(mario.getX(), 170);
        }
    }
    cout << mario.getX() << endl;
        update(mario);
        text.setPosition(camara.getCenter().x-190, 30);
        text2.setPosition(camara.getCenter().x-110, 30);
        text3.setPosition(camara.getCenter().x-50, 30);
        text4.setPosition(camara.getCenter().x+70, 30);
        text5.setPosition(camara.getCenter().x+125, 30);
        coin.setPosition(camara.getCenter().x+30, 28);
        textX.setPosition(camara.getCenter().x+50, 30);
        fin.setPosition(camara.getCenter().x-40, 150);
        
    window.setView(camara);
    window.draw(text);
}

