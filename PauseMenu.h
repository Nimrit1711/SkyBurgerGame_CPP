#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Score.h"

using namespace std;
using namespace sf;

class PauseMenu {

public:
    enum Option { RESTART, RESUME};  // Pause options

private:
    int currentSelection;  // Track which menu option is selected
    vector<string> menuOptions;  // The list of pause menu options (Resume, Restart)
    Text title;  // Title for the pause menu
    Font menuFont;  // Font for the text
    Text scoreText;  // Current score display
    Text bestScoreText;  // Best score display
    bool isPaused;  // Whether the game is paused or not
    Option SelectedOption;  // Store the confirmed option   

public:
    PauseMenu();
    void handleInput(RenderWindow &window);  // Handle user input (up/down keys, enter to confirm)
    void renderMenu(RenderWindow &window, const Score& score);  // Render the pause menu
    //bool isGamePaused() const;  // Return whether the game is paused
    Option getConfirmedOption() const;     // Return the confirmed option
};


#endif
