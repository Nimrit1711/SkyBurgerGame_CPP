#include "PauseMenu.h"
#include <iostream>

// Constructor for Pause Menu
PauseMenu::PauseMenu() : currentSelection(0), isPaused(false) {
    if (!menuFont.loadFromFile("arial.ttf")) {
        cout << "text not loaded!" << endl;
    }

    // Set up the title
    title.setFont(menuFont);
    title.setString("Pause");
    title.setCharacterSize(50);
    title.setFillColor(Color::White);

    // Add menu options
    menuOptions = {"Resume", "Restart"};

    // Set up score and best score texts
    scoreText.setFont(menuFont);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(Color::White);

    bestScoreText.setFont(menuFont);
    bestScoreText.setCharacterSize(30);
    bestScoreText.setFillColor(Color::White);
}

// Handle input for navigating the pause menu
void PauseMenu::handleInput(RenderWindow &window) {
    if (!isPaused) return;  // Only handle input when paused

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
                        case 0:  // Option 1: Resume
                            SelectedOption = RESUME;
                            break;
                        case 1:  // Option 2: Restart
                            SelectedOption = RESTART;
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

// Render the pause menu
void PauseMenu:: renderMenu(RenderWindow &window, const Score& score){
    
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
PauseMenu::Option PauseMenu::getConfirmedOption() const {
    return SelectedOption;  // Return the confirmed option stored in the class
}


