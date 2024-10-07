#include "Player.h"
#include <iostream>

Player::Player(Burger* burger)
    : burger(burger), lives(3), velocityX(0.5) {
    if (!playerTexture.loadFromFile("file.png")) {
      cout<<"player not loaded"<<endl;
    }            
    sprite.setTexture(playerTexture);   
    position = Vector2f(400.0f, 500.0f);  
    sprite.setScale(0.3f, 0.3f); 
    sprite.setPosition(position);   
    
}

void Player::handleInput(RenderWindow& window) {
    if (Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocityX =-0.5; //move by 5 pixels
        isMovingRight=false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocityX  = 0.5; //move by 5 pixels
        isMovingRight=true;
    }    
    checkBounds(window);
    sprite.setPosition(position);
}

void Player::update(float deltaTime, RenderWindow& window) {
    position.x += velocityX;
    sprite.setPosition(position);
}

void Player::render(RenderWindow& window) {
    window.draw(sprite);
}

FloatRect Player::getPlayerBounds() const {
    return sprite.getGlobalBounds();
}

void Player::loseLife() {
    if (lives > 0) {
        lives--;
    }
}

int Player::getLives() const {
    return lives;
}

bool Player::isAlive() const {
    return lives > 0;
}

Vector2f Player::getPlayerPosition() {
    return position;
}


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
    sprite.setPosition(position);
}
