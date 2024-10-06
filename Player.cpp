#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace sf;
using namespace std;

    //player constructor
    Player::Player(Burger* burger): burger(burger){
            if (!playerTexture.loadFromFile("file.png")) {
            cout<< "Error loading player texture" << endl;
        }
            playerObject.setTexture(&playerTexture);
            playerObject.setSize(Vector2f(100,100));
            playerPosition=Vector2f(100.0f,500.0f);
            playerObject.setPosition(playerPosition);
            Velocity = 0.5;
            isAlive = true;
            lives = 3;
        }

    int Player:: getLives(){
        return lives;
    }


    void Player:: updateMovement(const sf::RenderWindow& window){
            if (Keyboard::isKeyPressed(Keyboard::Key::Left)){
                Velocity=-0.5;
                
            } else if (Keyboard::isKeyPressed(Keyboard::Key::Right)){
                Velocity=0.55;
            }

            playerPosition.x += Velocity;
            checkBounds(window); // checks bounds first then sets the position
            playerObject.setPosition(playerPosition);
        
            //burger->renderBurger(window, playerPosition);
    }  


    void Player::renderPlayer(RenderWindow& window) {
        window.draw(playerObject);  //renders player on the game window
        
    }

    bool Player:: isALive() const{
        if (lives>0){
            return true;
            cout<< "Player is  alive"<<endl;
            
        } else{
            return false;
            cout<< "Player is not alive"<<endl;
        }
    }

    void Player:: loseLife(){
        if (lives>0){
        --lives;
        }
        cout<<"lives after reduction: "<< getLives()<<endl;
        
        if (lives == 0) {
        isAlive = false;
        cout << "Player is dead!" << endl;
    }
}
    
    void Player::checkBounds(const sf::RenderWindow& window) {
        
        if (playerPosition.x < -playerObject.getSize().x) {
            playerPosition.x = window.getSize().x;
        }
        if (playerPosition.x > window.getSize().x) {
            playerPosition.x = -playerObject.getSize().x;
        }
}

FloatRect Player:: getPlayerBounds() const {
    return playerObject.getGlobalBounds();
}

Vector2f Player::getPlayerPosition() const {
    return playerObject.getPosition();
}
