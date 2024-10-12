#include "IntroductionMenu.h"
#include "Game.h"
#include "GameMode.h"
#include "SettingsMenu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


// Main loop that handles showing the settings menu and launching the game
int main() {
    RenderWindow window(sf::VideoMode(900, 800), "Sky Burger Game");
    IntroductionMenu mainMenu;
    SettingsMenu settingsMenu;

    bool onSettingsScreen = false; // determines if player is on setting screen
    bool spacePressed = false;  // determines if space has been pressed 
    
    while (window.isOpen()) {
        if (!onSettingsScreen) {
            // Renders the introduction menu first
            mainMenu.renderMenu(window);
            
            // Wait for the space key to transition to settings
            if (mainMenu.handleInput(window)) {
                if (!spacePressed) {  // Only switch if space hasn't been pressed
                    onSettingsScreen = true;  // Switch to settings screen
                    spacePressed = true;      // Set flag to prevent repeat
                }
            } else {
                spacePressed = false;  // Reset flag if space is not pressed
            }
        } else {
            settingsMenu.handleInput(window);
            settingsMenu.renderMenu(window);

            // Check if player wants to go back to intro menu
            if (settingsMenu.isGoingBackToIntro()) {
                onSettingsScreen = false;  // Go back to the intro screen
                spacePressed = true; 
            }

            // If the player has confirmed their difficulty selection, start the game
            if (settingsMenu.isSelectionConfirmed()) {
                // Map SettingsMenu::Difficulty to GameMode::Difficulty
                GameMode::Difficulty selectedGameMode;
                switch (settingsMenu.getConfirmedDifficulty()) {
                    case SettingsMenu::EASY:
                        selectedGameMode = GameMode::Difficulty::Easy;
                        break;
                    case SettingsMenu::DEFAULT:
                        selectedGameMode = GameMode::Difficulty::Normal;
                        break;
                    case SettingsMenu::HARD:
                        selectedGameMode = GameMode::Difficulty::Hard;
                        break;
                }

                // Start game
                Game game(selectedGameMode,window);
               
                    game.run();
                              
                break;  // Exit after the game ends
            }
        }
    }

    return 0;
}
