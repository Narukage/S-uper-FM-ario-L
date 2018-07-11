#include "Map.h"

Map::Map() {
    
    if(!textura.loadFromFile("assets/sprites/box.png")){
        std::cout << "Error al cargar la textura." << std::endl;
        exit(-1);
    }
    
    if(!textura2.loadFromFile("assets/sprites/tubo.png")){
        std::cout << "Error al cargar la textura." << std::endl;
        exit(-1);
    }
    
    if(!textura3.loadFromFile("assets/sprites/cascada.png")){
        std::cout << "Error al cargar la textura." << std::endl;
        exit(-1);
    }
    
    if(!textura4.loadFromFile("assets/sprites/caja.png")){
        std::cout << "Error al cargar la textura." << std::endl;
        exit(-1);
    }
    
    caja.setTexture(textura4);
    
    cascada.setTexture(textura3);
    tubo.setTexture(textura2);
    
    sprite.setTexture(textura);
    sprite.setScale(1.1,1.1);
    
    TiXmlDocument doc;

    if(!doc.LoadFile("assets/map.tmx")){
       std::cout << "Error al cargar el mapa." << std::endl;
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
    


    if(!_tilesetTexture.loadFromFile("assets/mltilesetbs.png")){
        std::cout << "Error al cargar el tileset." << std::endl;
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
    string *name=new string[_numlayers];
    int j=0;
    int l=0;
       
    //Leo los tiles
            for(int l=0;l<_numlayers;l++){
                TiXmlElement *data= layer->FirstChildElement("data")->FirstChildElement("tile");
                name[j]= (string)layer->Attribute("name");
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

void Map::drawTile(sf::RenderWindow &window){
    for(int y=0; y<_height; y++){
            for(int x=0; x<_width; x++){
                if(_tilemapSprite[0][y][x]!=NULL){
                    window.draw(*(_tilemapSprite[0][y][x]));
                }
            }
        }
    
     for(int y=0; y<_height; y++){
            for(int x=0; x<_width; x++){
                if(_tilemapSprite[1][y][x]!=NULL){
                    window.draw(*(_tilemapSprite[1][y][x]));
                    
                }
            }
        }
    
    sprite2 = sprite;
    sprite.setPosition(251, 178.5);
    sprite2.setPosition(271, 178.5);
    tubo.setPosition(336, 211);
    sprite3 = sprite;
    sprite3.setPosition(818, 178.5);
    cascada.setPosition(589.5, 241);
    caja.setPosition(568, 195.5);
    caja2 = caja;
    caja.setPosition(589.5, 195.2);
    
    window.draw(sprite);
    window.draw(sprite2);
    window.draw(sprite3);
    window.draw(tubo);
    window.draw(cascada);
    window.draw(caja);
   
}

Map::~Map() {
}

