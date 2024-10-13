//Tests the collision detector

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Player.h"
#include "FoodItem.h"
#include "FallingObjects.h"
#include "Burger.h"
#include "Lettuce.h"
#include "Tomato.h"
#include "Patty.h"

using namespace sf;
using namespace std;

// Helper function for collision detection (AABB)
bool checkCollision(const RectangleShape& player, const RectangleShape& fallingObject) {
    return player.getGlobalBounds().intersects(fallingObject.getGlobalBounds());
}

int main() {
    // Initialize game window
    RenderWindow gameWindow(VideoMode(800, 800), "Sky Burger", Style::Close | Style::Titlebar);

    // Burger player (bun) controlled by the player
    RectangleShape burgerPlayer;
    Vector2f bunPosition(100.0f, 650.0f);
    burgerPlayer.setPosition(bunPosition);
    burgerPlayer.setSize(Vector2f(100, 100));

    // Player bun movement velocity
    float xVelocity = 0.5f;

    // Load bun texture with error handling
    Texture bunTexture;
    if (!bunTexture.loadFromFile("file.png")) {
        cout << "Error: Failed to load texture 'file.png'" << endl;
        return -1; // Exit if texture not found
    }
    burgerPlayer.setTexture(&bunTexture);

    // Random seed initialization
    srand(static_cast<unsigned int>(time(0)));

    // Vector to hold all falling items as shapes (directly using RectangleShape)
    vector<RectangleShape> fallingItems;

    // Spawn timers and game loop timing
    Clock clock;
    float spawnTimer = 0.0f;
    const float spawnInterval = 1.0f; // Spawn every 1 second
    const float cameraMoveSpeed = 0.5f;
    const float halfWindowHeight = gameWindow.getSize().y / 2;

    // Main game loop
    while (gameWindow.isOpen()) {
        // Poll events
        Event evnt;
        while (gameWindow.pollEvent(evnt)) {
            if (evnt.type == Event::Closed) {
                gameWindow.close();
            }
        }

        // Handle player movement
        if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
            xVelocity = -0.5f;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
            xVelocity = 0.55f;
        }
        
        bunPosition.x += xVelocity;

        // Wrap around the screen horizontally
        if (bunPosition.x < -burgerPlayer.getSize().x) {
            bunPosition.x = gameWindow.getSize().x;
        }
        if (bunPosition.x > gameWindow.getSize().x) {
            bunPosition.x = -burgerPlayer.getSize().x;
        }

        burgerPlayer.setPosition(bunPosition);

        // Spawn falling items at random intervals
        float deltaTime = clock.restart().asSeconds();
        spawnTimer += deltaTime;
        if (spawnTimer >= spawnInterval) {
            spawnTimer = 0.0f;

            // Randomly select a food type to spawn
            float randomX = static_cast<float>(rand() % gameWindow.getSize().x);
            RectangleShape fallingObject;
            fallingObject.setPosition(Vector2f(randomX, 0.0f)); // Spawn at the top with random X position
            fallingObject.setSize(Vector2f(50, 50)); // Set size of falling objects
            fallingObject.setFillColor(Color::Green); // Just to visualize it

            // Add falling object to the list
            fallingItems.push_back(fallingObject);
        }

        // Update falling items and check for collisions
        for (auto it = fallingItems.begin(); it != fallingItems.end(); ) {
            // Move the falling object downwards
            it->move(0.0f, 200.0f * deltaTime); // Move by speed * deltaTime

            // Check collision between player bun and the falling object
            if (checkCollision(burgerPlayer, *it)) {
                // Handle collision (e.g., stack the ingredient on the bun)
                // You can add your logic to handle the collision here.
                
                it = fallingItems.erase(it);  // Remove the item if it's caught
            } else {
                ++it;
            }
        }

        // Render
        gameWindow.clear(Color(135, 206, 235)); // Sky color

        // Draw falling items
        for (auto& item : fallingItems) {
            gameWindow.draw(item); // Draw each falling item directly
        }

        // Draw player-controlled bun
        gameWindow.draw(burgerPlayer);

        gameWindow.display();
    }

    return 0;
}