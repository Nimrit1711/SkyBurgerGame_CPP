//Testing player movement and player lives 


#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Burger.h"
#include <iostream>

using namespace sf;

int main() {
    // Create a render window
    RenderWindow window(VideoMode(800, 600), "Player Class Test");

    // Create a Burger object (as required by Player constructor)
    Burger burger;

    // Create a Player object, passing a pointer to the Burger object
    Player player(&burger);

    // Main game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Handle input (e.g., movement)
        player.handleInput(window);

        // Test loseLife function when "L" key is pressed
        if (Keyboard::isKeyPressed(Keyboard::Key::L)) {
            player.loseLife();
            std::cout << "Player lost a life! Lives remaining: " << player.getLives() << std::endl;
        }

        // Update the player (e.g., movement, checking bounds)
        player.update(0.016f, window);  // Assume 60 FPS, so deltaTime = 1/60 = 0.016

        // Clear the window
        window.clear(Color(135, 206, 235));  // Sky blue background color

        // Render the player
        player.render(window);

        // Display the updated window
        window.display();
    }

    return 0;
}
