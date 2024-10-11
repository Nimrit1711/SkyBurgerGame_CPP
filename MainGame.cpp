#include <SFML/Graphics.hpp>
#include "Player.h"            // Example game object
#include "Hazards.h"           // Example game hazard
#include "PauseMenu.h"         // Pause menu
#include "Game.h"              // Overall game class
#include <iostream>

int main() {
    // Create the main SFML window
  RenderWindow gameWindow(VideoMode(800,800), "Sky Burger", Style::Close | Style::Titlebar);

     while (gameWindow.isOpen())
    {
        Event evnt;
        while (gameWindow.pollEvent(evnt))
        {
            switch(evnt.type)
            {
            case Event::Closed:
                gameWindow.close();
                break;          
            
            }
        }
    }

    // Variables for game state management
    bool isPaused = false;        // Track if the game is paused
    int currentScore = 0;         // Player's current score
    int bestScore = 100;          // Best score recorded

    // Main game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Handle Pause and Game State Switching
            if (!isPaused) {
                // Normal game input handling
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
                    isPaused = true;
                }
            } else {
                // If the game is paused, pass input to the pause menu
                pauseMenu.handleInput(window);

                // Resume or Restart based on Pause Menu input
                if (!pauseMenu.isGamePaused()) {
                    PauseMenu::Option option = pauseMenu.getConfirmedOption();
                    if (option == PauseMenu::RESUME) {
                        isPaused = false;  // Resume game
                    } else if (option == PauseMenu::RESTART) {
                        currentScore = 0;  // Reset score
                        isPaused = false;  // Unpause and restart
                    }
                }
            }
        }

        // Update Game Logic and Render if not paused
        if (!isPaused) {
            // Clear the window
            window.clear();

            // Update and render game objects
            player.update();       // Update player
            hazard.update();       // Update hazards
            player.render(window); // Render player
            hazard.render(window); // Render hazards

            // Update the score and other game elements

            // Display everything
            window.display();
        } else {
            // If paused, render the pause menu
            pauseMenu.renderMenu(window, currentScore, bestScore);
        }
    }

    return 0;
}
