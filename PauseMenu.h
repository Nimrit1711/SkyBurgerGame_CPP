#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>



class PauseMenu {

public:
    enum Option { RESTART, RESUME};  // Pause options

private:
    int currentSelection;  // Track which menu option is selected
    std::vector<std::string> menuOptions;  // The list of pause menu options (Resume, Restart)
    sf::Text title;  // Title for the pause menu
    sf::Font menuFont;  // Font for the text
    sf::Text scoreText;  // Current score display
    sf::Text bestScoreText;  // Best score display
    bool isPaused;  // Whether the game is paused or not
    Option SelectedOption;  // Store the confirmed option   

public:
    PauseMenu();
    void handleInput(sf::RenderWindow &window);  // Handle user input (up/down keys, enter to confirm)
    void renderMenu(sf::RenderWindow &window, int currentScore, int bestScore);  // Render the pause menu
    //bool isGamePaused() const;  // Return whether the game is paused
    Option getConfirmedOption() const;     // Return the confirmed option
};


#endif
