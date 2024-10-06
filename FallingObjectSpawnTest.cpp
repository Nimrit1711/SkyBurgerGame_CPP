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

        // Updates the falling items
        for (auto& item : fallingItems) {
            item->update(deltaTime);
            item->checkCollision(player, burger);
        }

        
        window.clear(Color(135, 206, 235));

        //loop for rendering falling ingredients
        for (auto& item : fallingItems) {
            item->render(window);
        }

        player.render(window); 
        burger.render(window, player.getPlayerPosition()); 
        window.display();
    }

    return 0;
}
