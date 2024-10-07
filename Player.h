#ifndef PLAYER_H
#define PLAYER_H

#include "Burger.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Player {
private:
    Vector2f position;
    Sprite sprite;
    Texture playerTexture;
    Burger* burger;
    int lives;
    float velocityX; 
    bool isMovingRight; 
    float speed;
    bool isBound;
    

public:
    Player(Burger* burger);
    void handleInput(RenderWindow& window);
    void update(float deltaTime, RenderWindow& window);
    void render(RenderWindow& window);
    FloatRect getPlayerBounds() const;
    void loseLife();
    int getLives() const;
    bool isAlive() const;
    Vector2f getPlayerPosition();
    void checkBounds(const RenderWindow& window); 
    void setPosition(const Vector2f& newPosition);
};

#endif 
