//tests the introduction menu

#include <SFML/Graphics.hpp>
#include "IntroductionMenu.h"

int main() {
    // Create a window for testing the introduction menu
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test Introduction Menu");

    // Create an IntroductionMenu object
    IntroductionMenu introMenu;

    // Main loop to test the introduction menu
    while (window.isOpen()) {
        // Handle input and check if any key is pressed
        if (introMenu.handleInput(window)) {
            window.close();  // Close the window once a key is pressed
        }

        // Render the introduction menu
        introMenu.renderMenu(window);
    }

    return 0;
}
