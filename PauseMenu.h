#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class PauseMenu {
private:
    int currentSelection;  // Track which menu option is selected
    std::vector<std::string> menuOptions;  // The list of pause menu options (Resume, Restart)
    sf::Text title;  // Title for the pause menu
    sf::Font menuFont;  // Font for the text
    sf::Text scoreText;  // Current score display
    sf::Text bestScoreText;  // Best score display
    bool isPaused;  // Whether the game is paused or not

public:
    PauseMenu();
    void handleInput(sf::RenderWindow &window);  // Handle user input (up/down keys, enter to confirm)
    void renderMenu(sf::RenderWindow &window, int currentScore, int bestScore);  // Render the pause menu
    bool isGamePaused();  // Return whether the game is paused
    void togglePause();  // Toggle between paused and unpaused states
    int getSelectedOption();  // Return the selected menu option
};

#endif
