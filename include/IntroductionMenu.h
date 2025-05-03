//Manages the user interface and interaction for introduction

#ifndef INTRODUCTIONMENU_H
#define INTRODUCTIONMENU_H

#include <SFML/Graphics.hpp>
#include <string>

class IntroductionMenu {
private:
    sf::Text title;        
    sf::Text instructions; 
    sf::Font menuFont;     
    sf::Font titleFont;   
    
  
    
public:
    IntroductionMenu();
    void renderMenu(sf::RenderWindow &window);  // Render the introduction menu
    bool handleInput(sf::RenderWindow &window); // Handle key press to continue
    
};

#endif 
