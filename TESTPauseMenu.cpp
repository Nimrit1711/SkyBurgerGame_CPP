#include <SFML/Graphics.hpp>
#include "PauseMenu.h"
#include <iostream>

int main() {
    // Create an SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pause Menu Test");

    // Create a PauseMenu object
    PauseMenu pauseMenu;

    // Variables to simulate scores
    int currentScore = 50;
    int bestScore = 100;

    // Set the game as paused manually for the test
    bool isPaused = true; 
    // Main game loop
    while (window.isOpen()) {
        // Handle input for the pause menu
        pauseMenu.handleInput(window);

        // Clear the window
        window.clear();

        // Render the pause menu if the game is paused
        if (isPaused) {
            pauseMenu.renderMenu(window, currentScore, bestScore);
        }

        // Check if the user has confirmed an option
        if (!pauseMenu.isGamePaused()) {
            // Retrieve and print the confirmed option
            PauseMenu::Option option = pauseMenu.getConfirmedOption();
            if (option == PauseMenu::RESUME) {
                std::cout << "Resume selected. Exiting pause menu.\n";
                isPaused = false;  // Unpause the game (handled by another class in your game)
            } else if (option == PauseMenu::RESTART) {
                std::cout << "Restart selected.\n";
                // Here you would restart the game logic
                isPaused = false;
            }

            // Close the window after resume or restart for the test case
            window.close();
        }

        // Display the window content
        window.display();
    }

    return 0;
}
