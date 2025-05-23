//Test to see the frequency at which objects appear on the window

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
using namespace sf;
using namespace std;

//compile code: g++ FallingObjectSpawnTest.cpp Player.cpp Burger.cpp FoodItem.cpp Tomato.cpp Patty.cpp Lettuce.cpp -lsfml-graphics -lsfml-window -lsfml-system

int main() {
    // Seeds random number generator
    srand(static_cast<unsigned int>(time(0)));

    RenderWindow window(VideoMode(800, 600), "Sky Burger Game");

    Burger burger;
    Player player(&burger);

    // Vector to store falling food items
    vector<unique_ptr<FallingObjects>> fallingItems;

    Clock clock;
    float spawnTimer = 0.0f;
    float spawnInterval = 1.0f; // Spawns every 1 second
    const float cameraMoveSpeed = 0.5f; 
    const float halfWindowHeight = window.getSize().y / 2;

    // Main game loop
    while (window.isOpen()) {
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
            int randomFood = rand() % 3; 

            unique_ptr<FallingObjects> newFoodItem;
            if (randomFood == 0) {
                newFoodItem = make_unique<Lettuce>();
            } else if (randomFood == 1) {
                newFoodItem = make_unique<Tomato>();
            } else {
                newFoodItem = make_unique<Patty>();
            }

            // sets the ingredients starting position with random X
            newFoodItem->setPosition(Vector2f(randomX, 0.0f));

            // Adds the new item to the vector
            fallingItems.push_back(move(newFoodItem));
        }

       
        // Update falling items and check for collisions
        for (auto it = fallingItems.begin(); it != fallingItems.end(); ) {
        (*it)->update(deltaTime);
        (*it)->checkCollision(player, burger);

        // Remove food item if caught
        if (dynamic_cast<FoodItem*>(it->get())->getIsCaught()) {
            it = fallingItems.erase(it);
        } else {
            ++it;
        }
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
