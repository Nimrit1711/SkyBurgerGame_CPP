#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
using namespace std;
using namespace sf;

class SettingsMenu {
public:
    enum Difficulty { EASY, DEFAULT, HARD };  // Difficulty levels

private:
    int currentSelection;  // Track which difficulty is selected
    Difficulty selectedDifficulty;  // Store the confirmed difficulty
    vector<string> menuOptions;  // The list of difficulty options
    Text title;  // Title menu
    Font titleFont;
    Font menuFont;  
    Text prompt;  // Text prompt
    bool selectionConfirmed;  // Whether the selection is confirmed
    

public:
    SettingsMenu();
    void handleInput(sf::RenderWindow &window);  // Handle user input (up/down keys, space to confirm)
    void renderMenu(sf::RenderWindow &window);  // Render the settings menu
    Difficulty getConfirmedDifficulty();  // Return the confirmed difficulty
    bool isSelectionConfirmed();  // Check if selection has been confirmed
    bool backToIntro; // going back to this menu 
    bool isGoingBackToIntro() const; // to dectect if player want to go back
};
 
#endif

