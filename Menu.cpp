#include "Menu.h"

// Constructor
Menu::Menu() {
    currentSelection = 0; 
    // Set up font
    menuFont.loadFromFile("SuperWater.ttf");
    textFont.loadFromFile("arial.ttf");

    // Set up the title
    title.setFont(menuFont);
    title.setString("Sky Burger");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::White);

    // Menu options
    menuOptions = {"How to Play", "Settings"};

    // Instruction text for "How to Play"
    instructionText.setFont(textFont);
    instructionText.setCharacterSize(30);
    instructionText.setFillColor(sf::Color::White);

    // Set up difficulty settings
    difficultyText.setFont(textFont);
    difficultyText.setCharacterSize(40);
    difficultyText.setFillColor(sf::Color::White);
    difficultyLevel = "Default"; // Default difficulty level
}

// Destructor
Menu::~Menu() {
    // Clean up if necessary
}

// Display the main menu
void Menu::displayMainMenu() {
    menuOptions = {"How to Play", "Settings"};
}

// Display the How to Play screen
void Menu::displayHowToPlay() {
    instructionText.setString("How to Play:\n"
                              "1. Collect freefalling ingredients\n"
                              "   from the sky to build your burger.\n"
                              "   One point per ingredient. Golden\n"
                              "   ingredients give an extra point.\n"
                              "2. Each game gives the player 3 health\n"
                              "   points. Collect non-edible ingredients\n"
                              "   and lose 1 health point.\n"
                              "3. Once all health points are lost, the\n"
                              "   game ends.\n\n"
                              "Press any key to continue.");
}

// Display the Settings screen for difficulty selection
void Menu::displaySettingsMenu() {
    menuOptions = {"Easy", "Default", "Hard"};
}

// Handles player's input for navigating the menu
void Menu::handleInput() {
 
}

// Renders the menu screen
void Menu::renderMenu(sf::RenderWindow &window) {
    window.clear();

    // Render the title
    title.setPosition(window.getSize().x / 2 - title.getGlobalBounds().width / 2, 50);
    window.draw(title);

    // Check which screen to render
    if (currentSelection == 0) {
        // Render the "How to Play" screen
        instructionText.setPosition(50, 150);
        window.draw(instructionText);
    } else if (currentSelection == 1) {
        // Render the "Settings" screen
        for (size_t i = 0; i < menuOptions.size(); ++i) {
            sf::Text menuItem;
            menuItem.setFont(menuFont);
            menuItem.setString(menuOptions[i]);
            menuItem.setCharacterSize(40);
            
            // Highlight current selection
            if (i == currentSelection) {
                menuItem.setFillColor(sf::Color::Red); // Highlighted in red
            } else {
                menuItem.setFillColor(sf::Color::White);
            }
            
            menuItem.setPosition(window.getSize().x / 2 - menuItem.getGlobalBounds().width / 2, 200 + i * 50);
            window.draw(menuItem);
        }
    }
    
    window.display();
}

// Changes the difficulty level (used for navigating the settings screen)
void Menu::changeDifficulty(int direction) {
    if (direction > 0 && difficultyLevel == "Easy") {
        difficultyLevel = "Default";
    } else if (direction > 0 && difficultyLevel == "Default") {
        difficultyLevel = "Hard";
    } else if (direction < 0 && difficultyLevel == "Hard") {
        difficultyLevel = "Default";
    } else if (direction < 0 && difficultyLevel == "Default") {
        difficultyLevel = "Easy";
    }
}
