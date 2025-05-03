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
    bool isMovingRight; // checks if player is moving right for input control
    float speed;
    bool isBound; // checks if player is within the window bounds
    bool isPoisoned; // checks if the player has been hit with poision bottle
    float poisonDuration;
    Clock poisonTimer;  // Timer to track poison duration 
    

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
    void applyPoison(float duration); // affects players speed
    void checkPoisonEffect(); // checks if posion is over
    
};

#endif 
