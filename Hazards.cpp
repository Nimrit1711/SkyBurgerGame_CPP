#include "Hazards.h"
#include <iostream>
    Hazards:: Hazards(const string& textureFile, float speed):hazardSpeed(speed){
        if (!hazardTexture.loadFromFile(textureFile)){
            cout<<"file not loaded"<<endl;
        }
        hazardSprite.setTexture(hazardTexture);
        hazardSprite.setScale(0.08f, 0.08f);
    }


    void Hazards:: update(float deltaTime){
        hazardSprite.move(0, hazardSpeed * deltaTime);
    }

    void Hazards::render(RenderWindow& window){
        window.draw(hazardSprite);
    }

    void Hazards::checkCollision(Player& player, Burger& burger) {
    if (isCaught) return; // Skip if already caught
     if (hazardSprite.getGlobalBounds().intersects(player.getPlayerBounds())) {
           player.loseLife(); 
          isCaught = true; // Mark as caught to prevent further collisions
         if (!player.isAlive()) {
               // Handle game over logic if required
              std::cout << "Game Over!" << std::endl;
            }
        }
    }


    FloatRect Hazards::getGlobalBounds() const{
        return hazardSprite.getGlobalBounds();
    }

    void Hazards::setPosition(const Vector2f& pos){
        hazardSprite.setPosition(pos);
    }