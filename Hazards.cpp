#include "Hazards.h"
#include <iostream>
    Hazards:: Hazards(const string& textureFile, float speed):hazardSpeed(speed), isCaught(false){
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
        if (getIsCaught()) {
            return; 
        }
        FloatRect hazardBounds = getGlobalBounds();
        FloatRect playerBounds = player.getPlayerBounds();
        float playerWidth = playerBounds.width;
        Vector2f playerPosition=player.getPlayerPosition();
        Vector2f topOfStack = burger.getTopOfStack(playerPosition);
        
        if (hazardBounds.intersects(FloatRect(topOfStack.x + playerWidth / 4, topOfStack.y, playerWidth / 2, hazardBounds.height))) {
            player.loseLife();  
            setIsCaught(true);

            if (!player.isAlive()) {
                cout<<"0 lives left. game over! "<<endl;
            }
        }
    }
    


    FloatRect Hazards::getGlobalBounds() const{
        return hazardSprite.getGlobalBounds();
    }

    void Hazards::setPosition(const Vector2f& pos){
        hazardSprite.setPosition(pos);
    }