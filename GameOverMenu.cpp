#include "GameOverMenu.h"
#include <iostream>

// Constructor for Game Over Menu
GameOverMenu::GameOverMenu() : currentSelection(0), isGameOver(false) {
    if (!menuFont.loadFromFile("arial.ttf")) {
        cout << "Font not loaded!" << endl;
    }

    // Set up the title
    title.setFont(menuFont);
    title.setString("Game Over");
    title.setCharacterSize(50);
    title.setFillColor(Color::White);

    // Add menu options
    menuOptions = {"Restart", "Exit"};

     // Set up score and best score texts
    scoreText.setFont(menuFont);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(Color::White);

    bestScoreText.setFont(menuFont);
    bestScoreText.setCharacterSize(30);
    bestScoreText.setFillColor(Color::White);
}

// Handle input for navigating the game over menu
void GameOverMenu::handleInput(RenderWindow &window) {
    if (!isGameOver) return;  // Only handle input when the game is over

    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();  // Close the window if requested
        }

        // Handle key press events using switch statements for better readability
        if (event.type == Event::KeyPressed) {
            switch (event.key.code) {
                case Keyboard::Up:
                    // Move up the list
                    currentSelection = (currentSelection > 0) ? currentSelection - 1 : menuOptions.size() - 1;
                    break;

                case Keyboard::Down:
                    // Move down the list
                    currentSelection = (currentSelection < menuOptions.size() - 1) ? currentSelection + 1 : 0;
                    break;

                case Keyboard::Enter:
                    // Use switch to handle selected options
                    switch (currentSelection) {
                        case 0:  // Option 1: Restart
                            selectedOption = RESTART;
                            break;
                        case 1:  // Option 2: Exit
                            selectedOption = EXIT;
                            break;
                        default:
                            break;
                    }
                    break;

                default:
                    break;
            }
        }
    }
}

// Render the game over menu
void GameOverMenu:: renderMenu(RenderWindow &window, const Score& score) {
    window.clear();

    // Render the title (centered at the top)
    title.setPosition(window.getSize().x / 2 - title.getGlobalBounds().width / 2, 50);
    window.draw(title);

    // Render the current score
    scoreText.setString("Score: " + std::to_string(score.getCurrentScore()));
    scoreText.setPosition(350, 150);
    window.draw(scoreText);

    // Render the best score
    bestScoreText.setString("Best: " + std::to_string(score.getHighestScore()));
    bestScoreText.setPosition(350, 200);
    window.draw(bestScoreText);

    // Render the menu options
    for (size_t i = 0; i < menuOptions.size(); ++i) {
        Text menuItem;
        menuItem.setFont(menuFont);
        menuItem.setString(menuOptions[i]);
        menuItem.setCharacterSize(40);

        // Highlight the currently selected option
        if (i == currentSelection) {
            menuItem.setFillColor(Color::Black);
            menuItem.setStyle(Text::Bold);
            menuItem.setOutlineColor(Color::White);
            menuItem.setOutlineThickness(2.0f);
        } else {
            menuItem.setFillColor(Color::White);
        }

        // Set position of the menu items
        menuItem.setPosition(window.getSize().x / 2 - menuItem.getGlobalBounds().width / 2, 300 + i * 60);
        window.draw(menuItem);
    }

    window.display();
}

// Return the selected option
GameOverMenu::Option GameOverMenu::getConfirmedOption() const {
    return selectedOption;  // Return the confirmed option stored in the class
}

void GameOverMenu:: reset() {
    currentSelection = 0; // Reset to the first option
    selectedOption = RESTART; // Default selection
}

void GameOverMenu::setGameOver(bool state) {
    isGameOver = state; // Set the game over state
}

