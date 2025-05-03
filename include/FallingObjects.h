#ifndef FALLINGOBJECTS_H
#define FALLINGOBJECTS_H

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
// Forward declarations
class Player;
class Burger;


class FallingObjects {
protected:
bool isCaught;
public:
    virtual void update(float deltaTime) = 0; // Update falling objects position
    virtual void render(RenderWindow& window) = 0; 
    virtual void checkCollision(Player& player, Burger& burger) = 0; // Checks for collisions
    virtual FloatRect getGlobalBounds() const = 0; // Get bounds for collision detection
    virtual void setPosition(const Vector2f& pos) =0; 
    virtual bool getIsCaught() const { return isCaught; }
    virtual void setIsCaught(bool caught) { isCaught = caught; }
};

#endif 
