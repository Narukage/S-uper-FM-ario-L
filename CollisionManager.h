#include <SFML/Graphics.hpp>
#include <iostream>

class CollisionManager{
public:
    CollisionManager();
    bool checkSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);
};

