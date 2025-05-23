#include "IntroductionMenu.h"
#include <iostream>
#include <SFML/Graphics/VertexArray.hpp>
using namespace std;

// Constructor for Introduction Menu
IntroductionMenu::IntroductionMenu() {
    if (!titleFont.loadFromFile("assets/fonts/SuperWater.ttf")) {
        cout<<"text not loaded!"<<endl;
    }

    if (!menuFont.loadFromFile("assets/fonts/arial.ttf")) {
        cout<<"text not loaded!"<<endl;
    }
    

    // Set up the title 
    title.setFont(titleFont);
    title.setString("Sky Burger"); 
    title.setCharacterSize(64);
    title.setFillColor(sf::Color(255, 140, 0));

    // Set up the instructions 
    instructions.setFont(menuFont);
    instructions.setString(
        
        "In Sky Burger, you take on the role of a master burger builder!\n"
        "Your goal is to catch delicious falling ingredients while avoiding hazardous objects.\n\n"
        "How to Play:\n"
        "1. Catch the Ingredients:\n"
        "   - Lettuce, Tomatoes, Cheese, and Patties fall from above.\n"
        "     Catch them to build your burger and score points!\n\n"
        "2. Beware of Hazards:\n"
        "   - Poison Bottles: These won't take away your lives, but will slow you down!\n"
        "   - Bombs, Socks, Banana peels: Colliding with them will cost you a life. Stay alert!\n\n"
        "3. Collect the Golden Coins:\n"
        "   - These special coins are worth 50 additional points!\n\n"
        "4. Game Modes:\n"
        "   - Normal Mode: Standard gameplay with regular ingredient and hazard spawn rates.\n"
        "   - Hard Mode: Increased hazards for a greater challenge.\n"
        "   - Freeplay Mode: Enjoy the game without worrying about lives!\n\n"
        "Are you ready to build the biggest burger ever? Press SPACE to start the game!"
    );
    instructions.setCharacterSize(20);  
    instructions.setFillColor(sf::Color(255, 255, 255));
    
}

// Render the introduction screen
void IntroductionMenu::renderMenu(sf::RenderWindow &window) {
    sf::VertexArray skyGradient(sf::Quads, 4);

    sf::Color topColor(197, 234, 250);   
    sf::Color bottomColor(170, 215, 240); 

    float width = window.getSize().x;
    float height = window.getSize().y;

    skyGradient[0].position = sf::Vector2f(0, 0);
    skyGradient[1].position = sf::Vector2f(width, 0);
    skyGradient[2].position = sf::Vector2f(width, height);
    skyGradient[3].position = sf::Vector2f(0, height);

    skyGradient[0].color = topColor;
    skyGradient[1].color = topColor;
    skyGradient[2].color = bottomColor;
    skyGradient[3].color = bottomColor;


    window.draw(skyGradient);

   
    title.setPosition(window.getSize().x / 2 - title.getGlobalBounds().width / 2, 40);
    window.draw(title);

   
    instructions.setPosition(window.getSize().x / 2 - instructions.getGlobalBounds().width / 2, 150);
    sf::Text shadow = instructions;
    shadow.setFillColor(sf::Color( 0, 0, 8)); 
    shadow.setPosition(instructions.getPosition().x + 1, instructions.getPosition().y + 1);
    window.draw(shadow);
    window.draw(instructions);
    
    window.display(); 
}

// Handle input and detect any key press
bool IntroductionMenu::handleInput(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();  // Close the window 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            return true;  // Return true if space is pressed
        }
    }
    return false;
}

