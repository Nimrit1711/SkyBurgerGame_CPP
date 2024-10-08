#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Menu {
private:
    int currentSelection; // Tracks which option is selected in the menu
    std::vector<std::string> menuOptions; // Stores a list of menu options
    sf::Text title; // Holds the title of the screen
    sf::Font menuFont; // displaying the title
    sf::Font textFont; // font for displaying information / settings
    sf::Text instructionText; // For How to Play text
    sf::Text difficultyText; // For displaying difficulty options
    std::string difficultyLevel; // Current difficulty level

public:
    Menu(); // Constructor
    ~Menu(); // Destructor

    // Function declarations
    void displayMainMenu(); // Displays the main menu with options like How to Play, Settings
    void displayHowToPlay(); // Displays the How to Play screen
    void displaySettingsMenu(); // Displays the Settings screen
    void handleInput(); // Handles player's input for navigating the menu
    void renderMenu(sf::RenderWindow &window); // Renders the window of the menu screen
    void changeDifficulty(int direction); // Changes the difficulty (up/down)
};

#endif
