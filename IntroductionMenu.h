//Manages the user interface and interaction for introduction

#ifndef INTRODUCTIONMENU_H
#define INTRODUCTIONMENU_H

#include <SFML/Graphics.hpp>
#include <string>

class IntroductionMenu {
private:
    sf::Text title;        // Title of the game
    sf::Text instructions; // Instructions for the user
    sf::Font menuFont;     // Font for the text
    sf::Font titleFont;     // Font for the text
    
public:
    IntroductionMenu();
    void renderMenu(sf::RenderWindow &window);  // Render the introduction menu
    bool handleInput(sf::RenderWindow &window); // Handle key press to continue
    
};

#endif 
