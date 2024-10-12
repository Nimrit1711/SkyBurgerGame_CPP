#include "SettingsMenu.h"
#include <iostream>


// Constructor for Settings Menu
SettingsMenu::SettingsMenu() : currentSelection(1), selectionConfirmed(false), backToIntro(false) {  // Default to "Default" option
    if (!menuFont.loadFromFile("arial.ttf")) {
        cout<<"text not loaded!"<<endl;
    }

    if (!titleFont.loadFromFile("SuperWater.ttf")) {
        cout<<"text not loaded!"<<endl;
    }

    // Set up the title
    title.setFont(titleFont);
    title.setString("Settings");
    title.setCharacterSize(50);
    title.setFillColor(Color(255,165,0));

    // Add difficulty options 
    menuOptions = {"Easy", "Default", "Hard"};

    // Set up the prompt to continue
    prompt.setFont(titleFont);
    prompt.setString("Press Space to continue");
    prompt.setCharacterSize(24);
    prompt.setFillColor(Color(255,165,0));

    // Default difficulty is set to "Default"
    selectedDifficulty = DEFAULT;
}

// Handle input for navigating and selecting difficulty settings
void SettingsMenu::handleInput(RenderWindow &window) {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();  // Close the window if manually requested
        }

        // Handle arrow key navigation
        if (event.type == Event::KeyPressed) {
            if (event.key.code == Keyboard::Up) { 
                // Move up the list
                if (currentSelection > 0) {
                    currentSelection--;
                } else {
                    currentSelection = menuOptions.size() - 1;  // Loop back to the bottom
                }
            }
            else if (event.key.code == Keyboard::Down) {
                // Move down the list
                if (currentSelection < menuOptions.size() - 1) {
                    currentSelection++;
                } else {
                    currentSelection = 0;  // Loop back to the top
                }
            }
            else if (event.key.code == Keyboard::Space) {
                // Update the selectedDifficulty based on the currentSelection
                switch (currentSelection) {
                    case 0:
                        selectedDifficulty = EASY;
                        break;
                    case 1:
                        selectedDifficulty = DEFAULT;
                        break;
                    case 2:
                        selectedDifficulty = HARD;
                        break;
                }

                // Set the selectionConfirmed flag to true
                selectionConfirmed = true;
            } 
            else if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                backToIntro = true;
                selectionConfirmed = false; 
            }
        }
    }
}

// Render the settings menu
void SettingsMenu::renderMenu(RenderWindow &window) {
    window.clear(Color(197, 234, 250));

    // Render the title (centered at the top)
    title.setPosition(window.getSize().x / 2 - title.getGlobalBounds().width / 2, 50);
    window.draw(title);

    // Render the difficulty options
    for (size_t i = 0; i < menuOptions.size(); ++i) {
        Text menuItem;
        menuItem.setFont(titleFont);
        menuItem.setString(menuOptions[i]);
        menuItem.setCharacterSize(50);

        // Highlight the currently selected option
        if (i == currentSelection) {
            menuItem.setFillColor(Color(156, 170, 53));
            menuItem.setStyle(Text::Bold);
            menuItem.setOutlineColor(Color(203, 67, 48));
            menuItem.setOutlineThickness(2.0f);
        } else {
            menuItem.setFillColor(Color(255,165,0));
        }

        // Set position of the menu items
        menuItem.setPosition(window.getSize().x / 2 - menuItem.getGlobalBounds().width / 2, 200 + i * 60);
        window.draw(menuItem);
    }

    // Render the prompt to press space to continue (centered at the bottom)
    prompt.setPosition(window.getSize().x / 2 - prompt.getGlobalBounds().width / 2, window.getSize().y - 100);
    window.draw(prompt);

    window.display();
}

// Return the currently confirmed difficulty option
SettingsMenu::Difficulty SettingsMenu::getConfirmedDifficulty() {
    return selectedDifficulty;
}

// Check if the selection has been confirmed (used for exiting the menu)
bool SettingsMenu::isSelectionConfirmed() {
    return selectionConfirmed;
}

// returns true 
bool SettingsMenu::isGoingBackToIntro() const {
    return backToIntro;
}
