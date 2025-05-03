//Test to see how and how frequent the hazards spawn

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <cstdlib> 
#include <iostream> 
#include <ctime>   
#include "Player.h"
#include "FoodItem.h"
#include "FallingObjects.h"
#include "Burger.h"
#include "Lettuce.h"
#include "Tomato.h"
#include "Onion.h"
#include "Patty.h"
#include "Cheese.h"
#include "Hazards.h"
#include "PoisonBottle.h"
#include "GoldenIngredient.h"
#include "Bomb.h"
#include "BananaPeel.h"
#include "Sock.h"
using namespace sf;
using namespace std;

//compile code: g++ HazardsSpawnTest.cpp Player.cpp Burger.cpp FoodItem.cpp Tomato.cpp Patty.cpp Lettuce.cpp Bomb.cpp Hazards.cpp Cheese.cpp Onion.cpp Sock.cpp BananaPeel.cpp PoisonBottle.cpp -lsfml-graphics -lsfml-window -lsfml-system
int main() {
    // Seeds random number generator
    srand(static_cast<unsigned int>(time(0)));

    RenderWindow window(VideoMode(900, 800), "Spawing Object test 3");

    Burger burger;
    Player player(&burger);

    // Vector to store falling food items
    vector<FallingObjects*> fallingItems;
    

    Clock clock;
    float spawnTimer = 0.0f;
    float spawnInterval = 1.0f; // Spawns every 0.8 second
    const float cameraMoveSpeed = 1.0f; 
    const float halfWindowHeight = window.getSize().y / 2;
    bool gameRunning = true; //bool for if the player is still alive
    // Main game loop
    while (window.isOpen()&& gameRunning) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

       
        float deltaTime = clock.restart().asSeconds();      
        player.handleInput(window);        
        player.update(deltaTime, window);

        // Spawn new ingredients at random time intervals
        spawnTimer += deltaTime;
        if (spawnTimer >= spawnInterval) {
            spawnTimer = 0.0f; // Reset spawn timer

            // Generate random X position within window width
            float randomX = static_cast<float>(rand() % window.getSize().x);

            // Randomly select a food type to spawn
            int randomSpawnType = rand() % 10; 

            FallingObjects* newItem = nullptr;
            if (randomSpawnType == 0) {
                newItem = new Lettuce();
            } else if (randomSpawnType == 1) {
                newItem = new Tomato();
            } else if (randomSpawnType==2){
                newItem = new Patty();
            } else if(randomSpawnType==3){
                newItem = new Cheese();
            }else if(randomSpawnType==4){
                newItem = new Onion();
            } else if (randomSpawnType==5){
                newItem = new Bomb();
            } else if (randomSpawnType==6){
                newItem = new Sock();
            } else if (randomSpawnType==7){
                newItem = new BananaPeel();
            } else if(randomSpawnType==8){
                newItem = new GoldenIngredient();
            }else {
                newItem = new PoisonBottle();
            }

            // sets the ingredients starting position with random X
            newItem->setPosition(Vector2f(randomX, 0.0f));

            // Adds the new item to the vector
            fallingItems.push_back(move(newItem));
        }

       
        // Update falling items and checks for collisions
        for (auto it = fallingItems.begin(); it != fallingItems.end(); ) { 
            (*it)->update(deltaTime);
            if (auto foodItem = dynamic_cast<FoodItem*>(*it)) { // if its a food item
                foodItem->checkCollision(player, burger);
                if (foodItem->getIsCaught()) {
                    it = fallingItems.erase(it);
                    continue;
                }
            } else if (auto hazard = dynamic_cast<Hazards*>(*it)) { // if object is a hazard
                hazard->checkCollision(player, burger);
                if (hazard->getIsCaught()) {
                    if (auto poisonBottle = dynamic_cast<PoisonBottle*>(hazard)) { // checks if its the poison bottle
                        poisonBottle->applyPoisonEffect(player);
                        //burger.startFlashing(0.03f);
                    } else {
                        player.loseLife();    //if its the other hazards, lose a life. 
                    }
                    //burger.startFlashing(1.f);
                    delete *it; // delete the dynamically allocated object                  
                    it = fallingItems.erase(it); // removes graphic
                    if (!player.isAlive()){  // if player is not alive. end the game
                        gameRunning = false;
                        std::cout<<"Total Points: "<<burger.getTotalPoints()<<std::endl;
                    }
                    continue;
                }
            }
            ++it;        
        }
        
         // camera logic.
        float topOfStackY = burger.getTopOfStack(player.getPlayerPosition()).y;
    
        // If the stack is above halfway the window height, the burger pile moves down
        if (topOfStackY < halfWindowHeight) {
            player.setPosition(Vector2f(player.getPlayerPosition().x, player.getPlayerPosition().y + cameraMoveSpeed));
            burger.moveDown(cameraMoveSpeed); 
        }
                
        window.clear(Color(197,234,250));

        //loop for rendering falling ingredients
        for (auto& item : fallingItems) {
            item->render(window);
        }
            
            player.render(window); 
            burger.render(window, player.getPlayerPosition(), player); 
            window.display();
        }

        // delter dynamically allocated objects
        for (auto& item : fallingItems) {
            delete item;
        }

    return 0;

}
