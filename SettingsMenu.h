#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class SettingsMenu {
public:
    enum Difficulty { EASY, DEFAULT, HARD };  // Difficulty levels

private:
    int currentSelection;  // Track which difficulty is selected
    Difficulty selectedDifficulty;  // Store the confirmed difficulty
    std::vector<std::string> menuOptions;  // The list of difficulty options
    sf::Text title;  // Title for the settings menu
    sf::Font menuFont;  // Font for the text
    sf::Text prompt;  // Text prompt to continue
    bool selectionConfirmed;  // Whether the selection is confirmed

public:
    SettingsMenu();
    void handleInput(sf::RenderWindow &window);  // Handle user input (up/down keys, space to confirm)
    void renderMenu(sf::RenderWindow &window);  // Render the settings menu
    Difficulty getConfirmedDifficulty();  // Return the confirmed difficulty
    bool isSelectionConfirmed();  // Check if selection has been confirmed
};

#endif

