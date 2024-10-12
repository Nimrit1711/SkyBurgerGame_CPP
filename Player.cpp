#include "Player.h"
#include <iostream>

Player::Player(Burger* burger)
    : burger(burger), lives(3), velocityX(0.9f), poisonDuration(0) {
    if (!playerTexture.loadFromFile("file.png")) {
      cout<<"player not loaded"<<endl;
    }            
    sprite.setTexture(playerTexture);   
    position = Vector2f(400.0f, 700.0f);  
    sprite.setScale(0.3f, 0.3f); 
    sprite.setPosition(position);   
    
}


//handles keyboard input from player
void Player::handleInput(RenderWindow& window) {
    float speedMultiplier=1.0f;
    if (isPoisoned){
        speedMultiplier=0.3f;
    }    
    
    if (Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocityX =-1.0*speedMultiplier; //move by 5 pixels
        isMovingRight=false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocityX  =1.0*speedMultiplier; //move by 5 pixels
        isMovingRight=true;
    }  

    checkBounds(window);
    sprite.setPosition(position);
}

//updates the players positon
void Player::update(float deltaTime, RenderWindow& window) {
    checkPoisonEffect();
    position.x += velocityX;
    sprite.setPosition(position);    
}

//renders the graphics
void Player::render(RenderWindow& window) {
    window.draw(sprite);
}

//gets players box dimensions 
FloatRect Player::getPlayerBounds() const {
    return sprite.getGlobalBounds();
}

void Player::loseLife() {
    if (lives > 0) {
        lives--;
        cout<<"lives left: "<<getLives()<<endl;
    }
}

//returns the players remaining lives
int Player::getLives() const {
    return lives;
}

//checks if the player is alive 
bool Player::isAlive() const {
    return lives > 0;
}

Vector2f Player::getPlayerPosition() {
    return position;
}

//checks and handles if the player moves outside of the game window 
void Player::checkBounds(const RenderWindow& window) {
    
     FloatRect playerBounds = sprite.getGlobalBounds();

    // Checks if the player goes out of the window bounds on the left
    if (position.x < -playerBounds.width) {
        position.x = window.getSize().x;
    }

    // Checks if the player goes out of the window bounds on the right
    if (position.x > window.getSize().x) {
        position.x = -playerBounds.width;
    }    

     // sets the position to the other end of the window 
    sprite.setPosition(position);
}

//sets the players position
void Player::setPosition(const Vector2f& newPosition) {
    position = newPosition; 
    sprite.setPosition(position); 
}

//applies the poision effect
void Player:: applyPoison(float duration){
    isPoisoned = true;
    poisonDuration = duration;
    poisonTimer.restart();      

}

// checks if the player is poisioned 
void Player::checkPoisonEffect() {
    if (isPoisoned) {
        // Check if poison duration has passed
        if (poisonTimer.getElapsedTime().asSeconds() >= poisonDuration) {
            isPoisoned = false;
        }
    }
}

void Player::playerReset() {
    lives = 3;  // Reset lives
    position = Vector2f(400.0f, 700.0f); 
    setPosition(Vector2f(position));  
}