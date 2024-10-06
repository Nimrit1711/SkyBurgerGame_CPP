// compile: g++ FallingObjectTest.cpp Player.cpp Burger.cpp FoodItem.cpp Lettuce.cpp -lsfml-graphics -lsfml-window -lsfml-system
#include <SFML/Graphics.hpp>
#include <memory>
#include "Player.h"
#include "Burger.h"
#include "Lettuce.h"
#include "Tomato.h"
using namespace sf;
using namespace std;


int main() {
    
    RenderWindow window(VideoMode(800, 600), "Sky Burger Game");

    
    Burger burger;

    
    Player player(&burger);

      vector<unique_ptr<FallingObjects>> foodItems;
      foodItems.push_back(make_unique<Lettuce>());
      foodItems.push_back(make_unique<Lettuce>());

    

    
    Clock clock;

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

        // Update the player and food item
       
        player.update(deltaTime, window);
        for (auto& foodItem : foodItems) {
            foodItem->update(deltaTime);
            foodItem->checkCollision(player, burger);  // Check for collision with each food item
        }

        
       
        
        // Render graphics
        window.clear(Color(135,206, 235));
        
        burger.render(window, player.getPlayerPosition()); 
        for (auto& foodItem : foodItems) {
            foodItem->render(window);
        } 
        player.render(window); 

    
        window.display();
    }

    return 0;
}
