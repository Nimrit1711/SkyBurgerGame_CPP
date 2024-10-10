#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class PauseMenu {

public:
    enum Option { RESTART, RESUME };  // Pause options

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
    bool isGamePaused();  // Return whether the game is paused
    void togglePause();  // Toggle the pause state
    Option getConfirmedOption() const;  // Return the confirmed option

};

<<<<<<< HEAD
#endif
=======
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();  // Close the window if requested
        }

        // Handle arrow key navigation and enter key for selection
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                // Move up the list
                if (currentSelection > 0) {
                    currentSelection--;
                } else {
                    currentSelection = menuOptions.size() - 1;  // Loop back to the bottom
                }
            } else if (event.key.code == sf::Keyboard::Down) {
                // Move down the list
                if (currentSelection < menuOptions.size() - 1) {
                    currentSelection++;
                } else {
                    currentSelection = 0;  // Loop back to the top
                }
            } else if (event.key.code == sf::Keyboard::Enter) {
                // Confirm the selected option (Resume or Restart)
                if (menuOptions[currentSelection] == "Resume") {
<<<<<<< HEAD
                    //togglePause();  // Unpause the game
=======
                    togglePause();  // Unpause the game
>>>>>>> e1608f780d44ce1cebb21edeb19c58cb0387ca48
                } else if (menuOptions[currentSelection] == "Restart") {
                    // Handle game restart 
                    //Do this in the game loop
                    
                }
            }
        }
    }
}

// Render the pause menu
void PauseMenu::renderMenu(sf::RenderWindow &window, int currentScore, int bestScore) {
    if (!isPaused) return;  // Only render when paused

    window.clear();

    // Render the title (centered at the top)
    title.setPosition(window.getSize().x / 2 - title.getGlobalBounds().width / 2, 50);
    window.draw(title);

    // Render the current score
    scoreText.setString("Score: " + std::to_string(currentScore));
    scoreText.setPosition(350, 150);
    window.draw(scoreText);

    // Render the best score
    bestScoreText.setString("Best: " + std::to_string(bestScore));
    bestScoreText.setPosition(350, 200);
    window.draw(bestScoreText);

    // Render the menu options
    for (size_t i = 0; i < menuOptions.size(); ++i) {
        sf::Text menuItem;
        menuItem.setFont(menuFont);
        menuItem.setString(menuOptions[i]);
        menuItem.setCharacterSize(40);

        // Highlight the currently selected option
        if (i == currentSelection) {
            menuItem.setFillColor(sf::Color::Black);
            menuItem.setStyle(sf::Text::Bold);
            menuItem.setOutlineColor(sf::Color::White);
            menuItem.setOutlineThickness(2.0f);
        } else {
            menuItem.setFillColor(sf::Color::White);
        }

        // Set position of the menu items
        menuItem.setPosition(window.getSize().x / 2 - menuItem.getGlobalBounds().width / 2, 300 + i * 60);
        window.draw(menuItem);
    }

    window.display();
}

// Return the selected option
int PauseMenu::getSelectedOption() {
    return currentSelection;
}
>>>>>>> 6e39bf8870e72296084de2126ad34185c0ec824b
