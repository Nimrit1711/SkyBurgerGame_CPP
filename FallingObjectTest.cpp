#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "Player.h"
#include "Burger.h"
#include "Lettuce.h"  // Include your other ingredient classes similarly
#include "Tomato.h"
#include "Patty.h"

using namespace sf;

int main() {
    // Create the main game window
    RenderWindow window(VideoMode(800, 600), "Faling Object Tester");
    window.setFramerateLimit(60); // Limit the frame rate

    // Create the Burger and Player objects
    Burger burger;
    Player player(&burger);

    // Game loop
    while (window.isOpen()) {
        // Handle events
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        // Update player movement
        player.updateMovement(window);

        // Simulate falling objects (in this case, we'll just add a lettuce)
        if (rand() % 100 < 2) {  // Randomly add a new lettuce every few frames
            auto lettuce = std::make_unique<Lettuce>(Vector2f(rand() % 800, 0)); // Random x position
            burger.addIngredient(std::move(lettuce));
        }

        // Clear the window
        window.clear(Color::White);

        // Render player and burger
        player.renderPlayer(window);
        burger.renderBurger(window, player.getPlayerPosition());

        // Display the contents of the window
        window.display();
    }

    return 0;
}
