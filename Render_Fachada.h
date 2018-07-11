#ifndef RENDER_FACHADA_H
#define RENDER_FACHADA_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "Animacion.h"
#include "Sprite.h"

class Render_Fachada {
public:
    
    //Teclas presionadas
    enum Presionado{
        none = 0,
        A = 1,
        D = 2,
        S = 3,
        W = 4,
        Space = 5,
        Salir = 6,
        Intro = 7
    };
    
    //Constructores y destructores
    Render_Fachada();
    Render_Fachada(const Render_Fachada& orig);
    virtual ~Render_Fachada();
    static Render_Fachada& instancia(){
        static Render_Fachada render_fachada;
        return render_fachada;
    }
    
    //Funciones principales
    void inicializar(int, int, std::string, int, bool);
    void actualizar();
    void dibujar(float);
    void limpiar();
    
    //Teclado
    void actualizar_teclado(); //actualiza el ultimo boton presionado
    
    //Sprites y animaciones individuales
    int Anyadir_animacion(const char *, sf::IntRect* , sf::Vector2i* , int , int, bool);
    int Anyadir_sprite(const char* , sf::IntRect , sf::Vector2i );
    void Mover_animacion(int, float, float);
    void Mover_sprite(int, float, float);
    Animacion* Devolver_animacion(int);
    Sprite* Devolver_sprite(int);
    void Borrar_animacion(int);
    void Borrar_sprite(int);
    
    //Mapa
    void cargar_mapa(int);
    void dibujar_mapa();
    
    //Dibujar HUD
    void cargarHUD();
    void dibujarHUD();
    
    //##########################################
    // GETTERS / SETTERS
    //##########################################
    Presionado getPresionado(){
        return presionado;
    }
    
private:
    //Datos generales
    Presionado presionado;       //Última tecla presionada
    
    sf::RenderWindow* ventana;   //Ventana principal del juego
    sf::Event evento;            //Evento principal del teclado
    std::vector<Animacion*> animaciones; //Lista de todas las animaciones a pintar
    std::vector<Sprite*> mapa;       //Lista de todos los sprites a pintar del mapa
    
    //Valores de estado
    int animacion_id;
    int sprite_id;
    
    //Tilemap
    int _width;
    int _tilewidth;

    int ***_tilemap;
    int _numlayers;
    int _height;
    int _tileheigth;

    sf::Sprite ****_tilemapSprite;
    sf::Sprite *_tilesetSprite;
    sf::Texture _tilesetTexture;
    
    //HUD
    sf::Font font;
    sf::Text text;
};

#endif /* RENDER_FACHADA_H */

