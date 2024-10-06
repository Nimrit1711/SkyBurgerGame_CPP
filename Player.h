// header file for Player Class
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Burger.h"
using namespace sf;
using namespace std;

class Player {
    private:
    //defning the graphics
    RectangleShape playerObject;
    Texture playerTexture;
    
    bool isAlive;   // determines if they are alive
    float Velocity;  // players speed
    Vector2f playerPosition;
    bool isBound;
    int lives;
    Burger* burger;


    public:
    Player(Burger* burger);
    
    void updateMovement(const sf::RenderWindow& window);   //moving functions for the player
     
    void renderPlayer(RenderWindow& window);  //render function for player
    
    int getLives();

    bool isALive() const; // checking if the player is alive

    void loseLife(); // taking the life away
    
    void checkBounds(const sf::RenderWindow& window); //prevents the player from going out of the window 

    FloatRect getPlayerBounds() const;

    Vector2f getPlayerPosition() const;

};

#endif
