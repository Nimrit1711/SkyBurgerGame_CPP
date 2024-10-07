#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <cstdlib> 
#include <ctime>   
#include "Player.h"
#include "FoodItem.h"
#include "FallingObjects.h"
#include "Burger.h"
#include "Lettuce.h"
#include "Tomato.h"
#include "Patty.h"
#include "Hazards.h"
#include "Bomb.h"
using namespace sf;
using namespace std;

//compile code: g++ HazardsSpawnTest.cpp Player.cpp Burger.cpp FoodItem.cpp Tomato.cpp Patty.cpp Lettuce.cpp Bomb.cpp Hazards.cpp -lsfml-graphics -lsfml-window -lsfml-system

int main() {
    // Seeds random number generator
    srand(static_cast<unsigned int>(time(0)));

    RenderWindow window(VideoMode(800, 600), "Spawing Object test 3");

    Burger burger;
    Player player(&burger);

    // Vector to store falling food items
    vector<unique_ptr<FallingObjects>> fallingItems;
    

    Clock clock;
    float spawnTimer = 0.0f;
    float spawnInterval = 1.0f; // Spawns every 1 second
    const float cameraMoveSpeed = 0.5f; 
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
            int randomSpawnType = rand() % 4; 

            unique_ptr<FallingObjects> newItem;
            if (randomSpawnType == 0) {
                newItem = make_unique<Lettuce>();
            } else if (randomSpawnType == 1) {
                newItem = make_unique<Tomato>();
            } else if (randomSpawnType==2){
                newItem = make_unique<Patty>();
            } else {
                newItem = make_unique<Bomb>();
            }

            // sets the ingredients starting position with random X
            newItem->setPosition(Vector2f(randomX, 0.0f));

            // Adds the new item to the vector
            fallingItems.push_back(move(newItem));
        }

       
        // Update falling items and checks for collisions
        for (auto it = fallingItems.begin(); it != fallingItems.end(); ) {
            (*it)->update(deltaTime);
            if (auto foodItem = dynamic_cast<FoodItem*>(it->get())) {
                foodItem->checkCollision(player, burger);
                if (foodItem->getIsCaught()){
                    it = fallingItems.erase(it);
                    continue;
                }
            } else if (auto hazard = dynamic_cast<Hazards*>(it->get())){
                hazard->checkCollision(player,burger);
                if (!player.isAlive()){
                    it=fallingItems.erase(it);
                    gameRunning = false;
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
        
        
        window.clear(Color(135, 206, 235));

        //loop for rendering falling ingredients
        for (auto& item : fallingItems) {
            item->render(window);
        }

        player.render(window); 
        burger.render(window, player.getPlayerPosition(), player); 
        window.display();
    }

    return 0;
}
