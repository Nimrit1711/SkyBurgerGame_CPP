#ifndef GAMEOVERMENU_H
#define GAMEOVERMENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Score.h"

using namespace std;
using namespace sf;

class GameOverMenu {
public:
   enum Option { EXIT };  // Game over options

private:
    int currentSelection;  // Tracks which menu option is selected
    vector<string> menuOptions;  // The list of game over menu options (Restart, Exit)
    Text title; 
    Font menuFont;  
    Text scoreText; 
    Text bestScoreText;
    bool isGameOver;  
    Option selectedOption;  // Stores the confirmed option
    

public:
   
    GameOverMenu(int currentScore, int highestScore);
    void renderMenu(sf::RenderWindow& window);
    void handleInput(RenderWindow &window);  // Handles user input 
    Option getConfirmedOption() const;  // Return the confirmed option
    void reset();
    void setGameOver(bool state);
    Text getTitle();
  
};

#endif
