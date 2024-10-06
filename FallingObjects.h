#ifndef FALLINGOBJECTS_H
#define FALLINGOBJECTS_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <SFML/System/Vector2.hpp>
#include "Player.h"
#include "Burger.h"
#include "Score.h"

class Player;  
class Burger;

// header file for Falling Object Class

using namespace sf;

class FallingObjects{
    
    protected:
    //initialising the falling object properties 
    bool isCaught; //tracks if the object is caught
    Vector2f positionOfObject;
    Vector2f Objectsize;
    
    //graphics 
    Texture objectTexture;
    RectangleShape objectShape;

    
    public:
    FallingObjects(const Vector2f& startingPosition);
    Vector2f getSize() const;
    virtual void updateObjectPosition(float Time)=0;
    virtual void renderObject(RenderWindow& window)=0;
    bool isOffScreen(const RenderWindow& window);
    virtual void checkCollision(Player& player, Burger& burger)=0;
    void setTexture(const string& textureFile); // sets the specific falling object png file
    void setPosition(const Vector2f& position);
    Vector2f getPosition() const;   
   
    

};

#endif