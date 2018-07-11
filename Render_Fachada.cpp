
//Includes de C++ o similar
#include <iostream>
#include "tinyxml.h"
#include "tinystr.h"

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
    
    _height = 0;
    _width  = 0;
}

//Actualizar la fachada
void Render_Fachada::actualizar()
{
    actualizar_teclado();
}


//Limpiar
void Render_Fachada::limpiar()
{
    animaciones.clear();
    mapa.clear();
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
    
    //Dibujar mapa
    dibujar_mapa();
    
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
    
    //Dibujar HUD
    ventana->draw(text);
    
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

Animacion* Render_Fachada::Devolver_animacion(int id)
{
    for(int i = 0; i < animaciones.size(); i++)
    {
        if(animaciones[i]->get_id() == id)
            return animaciones[i];
    }
    
    return nullptr;
}

Sprite* Render_Fachada::Devolver_sprite(int id)
{
    for(int i = 0; i < mapa.size(); i++)
    {
        if(mapa[i]->get_id() == id)
            return mapa[i];
    }
    
    return nullptr;
}

void Render_Fachada::Borrar_animacion(int id)
{
    for(int i = 0; i < animaciones.size(); i++)
    {
        if(animaciones[i]->get_id() == id)
            animaciones.erase(animaciones.begin()+i);
    }
    
}

void Render_Fachada::Borrar_sprite(int id)
{
    for(int i = 0; i < mapa.size(); i++)
    {
        if(mapa[i]->get_id() == id)
            mapa.erase(mapa.begin()+i);
    }
}

void Render_Fachada::cargar_mapa(int id)
{
    //Documento a leer
    TiXmlDocument doc;
    id = 0;
              
    //Carga del tmx
    if(id == 0)
    {   
        if(!doc.LoadFile("assets/sprites/diggermap.tmx")){
           std::cout << "Error al cargar el mapa." << std::endl;
        }
    }
    
    if(id == 1)
    {
        if(!doc.LoadFile("assets/sprites/diggermap2.tmx")){
           std::cout << "Error al cargar el mapa." << std::endl;
        }
    }
    
    TiXmlElement* map = doc.FirstChildElement("map");
    
    //Tamanio del mapa y de los tiles
    map->QueryIntAttribute("width",&_width);
    map->QueryIntAttribute("height",&_height);
    map->QueryIntAttribute("tilewidth",&_tilewidth);
    map->QueryIntAttribute("tileheight",&_tileheigth);
    
    //Leemos los tilesets
    TiXmlElement *img = map->FirstChildElement("tileset");//->FirstChildElement("image");  
    const char* filename = img->Attribute("source");
    
    if(id == 0)
    {
        if(!_tilesetTexture.loadFromFile("assets/sprites/diggertileset.png")){
            std::cout << "Error al cargar el tileset." << std::endl;
        }
    }
    
    if(id == 1)
    {
        if(!_tilesetTexture.loadFromFile("assets/sprites/diggertileset2.png")){
            std::cout << "Error al cargar el tileset." << std::endl;
        }
    }
    
    //Leemos diferentes capas
    map->FirstChildElement("layer");
    TiXmlElement *layer = map->FirstChildElement("layer");
    _numlayers=0;
    while(layer){
      _numlayers++;
      layer= layer->NextSiblingElement("layer");
    }

    //Reserva de memoria
    _tilemap=new int**[_numlayers];
    for(int i=0; i<_numlayers; i++){
        _tilemap[i]=new int*[_height];
    }

    for(int l=0; l<_numlayers; l++){
        for(int y=0; y<_height; y++){
            _tilemap[l][y]=new int[_width];
        }
    }

    layer = map->FirstChildElement("layer");
    std::string *name=new std::string[_numlayers];
    int j=0;
    int l=0;

    //Leo los tiles
    for(int l=0;l<_numlayers;l++){
        TiXmlElement *data= layer->FirstChildElement("data")->FirstChildElement("tile");
        name[j]= (std::string)layer->Attribute("name");
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width;x++){
                data->QueryIntAttribute("gid",&_tilemap[l][y][x]);
                data=data->NextSiblingElement("tile");
            }
        }
        layer= layer->NextSiblingElement("layer");
        j++;

    }

    //Reserva de memoria para los sprites
    _tilemapSprite=new sf::Sprite***[_numlayers];

    for(int l=0; l<_numlayers; l++){
        _tilemapSprite[l]=new sf::Sprite**[_height];
    }


    for(int l=0; l<_numlayers; l++){
        for(int y=0; y<_height; y++){
            _tilemapSprite[l][y]= new sf::Sprite*[_width];
            for(int x=0; x<_width; x++){
                _tilemapSprite[l][y][x]=new sf::Sprite();
            }
        }
    }

    int columns = _tilesetTexture.getSize().x / _tilewidth;
    int rows = _tilesetTexture.getSize().y / _tileheigth;


    _tilesetSprite =new sf::Sprite[columns*rows];
    int t=0;
    for(int y=0; y<rows; y++){
        for(int x=0; x<columns;x++){
            _tilesetSprite[t].setTexture(_tilesetTexture);
            _tilesetSprite[t].setTextureRect(sf::IntRect(x*_tilewidth,y*_tileheigth,_tilewidth,_tileheigth));
            t++;
        }
    }

    //Carga de Sprites
    for(int l=0; l<_numlayers; l++){
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width;x++){
                int gid=_tilemap[l][y][x]-1;
                if(gid>=rows*columns){ //Si entra, no lo está haciendo bien

                }
                else if(gid>0){ //Todo correcto
                    _tilemapSprite[l][y][x]=new sf::Sprite(_tilesetTexture,_tilesetSprite[gid].getTextureRect());
                    _tilemapSprite[l][y][x]->setPosition(x*_tilewidth,y*_tileheigth);
                }
                else{
                    _tilemapSprite[l][y][x]=NULL;
                }
            }
        }
    }
    
}

void Render_Fachada::dibujar_mapa()
{
    //Recorrer tileset pintando
    for(int y=0; y<_height; y++){
        for(int x=0; x<_width; x++){
            if(_tilemapSprite[0][y][x]!=NULL){
                ventana->draw(*(_tilemapSprite[0][y][x]));
            }
        }
    }
    
    for(int y=0; y<_height; y++){
        for(int x=0; x<_width; x++){
            if(_tilemapSprite[1][y][x]!=NULL){
                ventana->draw(*(_tilemapSprite[1][y][x]));

            }
        }
    }
}

void Render_Fachada::cargarHUD()
{
    //Cargar fuente
    if(!font.loadFromFile("assets/sprites/prstart.ttf"))
    {
        //Imprimir error
        std::cout<<"Se ha roto este bello texto"<<std::endl;
    }
    //Seleccionar fuente
    text.setFont(font);

    //Ponerle el string
    text.setString("Hello world");

    //Tamaño de letra
    text.setCharacterSize(24);

    //Color
    text.setFillColor(sf::Color::Blue);
    
    //Text position
    text.setPosition(50,10);
}

void Render_Fachada::dibujarHUD(int puntos, int limite)
{   
    std::string p = std::to_string(puntos);
    std::string l = std::to_string(limite);
    
    text.setString(p + "/" + l);
}