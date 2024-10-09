#include <SFML/Graphics.hpp>
#include "PauseMenu.h"
#include <iostream>

int main() {
    // Create a window for testing the pause menu
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test Pause Menu");

    // Create a PauseMenu object
    PauseMenu pauseMenu;

    // Simulate starting the game and then pausing it
    //pauseMenu.togglePause();  // Set the game to paused state

    // Dummy score data for testing
    int currentScore = 10;
    int bestScore = 100;

    // Main loop to test the pause menu
    while (window.isOpen()) {
        // Handle input and render the pause menu if the game is paused
        pauseMenu.handleInput(window);
        pauseMenu.renderMenu(window, currentScore, bestScore);

        // Check if "Resume" or "Restart" was selected
        if (!pauseMenu.isGamePaused()) {
            if (pauseMenu.getSelectedOption() == 0) {
                std::cout << "Game Resumed!" << std::endl;
            } else if (pauseMenu.getSelectedOption() == 1) {
                std::cout << "Game Restarted!" << std::endl;
                // Restart logic can be placed here
            }
            window.close();  // Close the window after confirming the selection
        }
    }

    return 0;
}
