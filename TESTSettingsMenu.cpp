#include <SFML/Graphics.hpp>
#include "SettingsMenu.h"
#include <iostream>

int main() {
    // Test difficulty settings with multiple selections
    sf::VideoMode windowSizes[] = {
        sf::VideoMode(800, 600),  // Standard size
    };

    for (auto& size : windowSizes) {
        // Create a window with each size
        sf::RenderWindow window(size, "Test Settings Menu - Multiple Selections");

        // Create a SettingsMenu object
        SettingsMenu settingsMenu;

        // Main loop for testing different selections
        while (window.isOpen()) {
            settingsMenu.handleInput(window);
            settingsMenu.renderMenu(window);

            // Check if selection has been confirmed
            if (settingsMenu.isSelectionConfirmed()) {
                // Output the confirmed selection to the console
                SettingsMenu::Difficulty difficulty = settingsMenu.getConfirmedDifficulty();
                switch (difficulty) {
                    case SettingsMenu::EASY:
                        std::cout << "Easy mode selected!" << std::endl;
                        break;
                    case SettingsMenu::DEFAULT:
                        std::cout << "Default mode selected!" << std::endl;
                        break;
                    case SettingsMenu::HARD:
                        std::cout << "Hard mode selected!" << std::endl;
                        break;
                }

                window.close();  // Close the window after confirming the selection
            }
        }
    }

    return 0;
}