#include "IntroductionMenu.h"
#include <iostream>
using namespace std;

// Constructor for Introduction Menu
IntroductionMenu::IntroductionMenu() {
    if (!titleFont.loadFromFile("SuperWater.ttf")) {
        cout<<"text not loaded!"<<endl;
    }

    if (!menuFont.loadFromFile("arial.ttf")) {
        cout<<"text not loaded!"<<endl;
    }

    // Set up the title 
    title.setFont(titleFont);
    title.setString("Sky Burger"); //only the title uses the title font
    title.setCharacterSize(50);
    title.setFillColor(sf::Color(255,165,0));

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
    instructions.setCharacterSize(20);  // Smaller size for instructions
    instructions.setFillColor(sf::Color(243, 181, 53));
}

// Render the introduction screen
void IntroductionMenu::renderMenu(sf::RenderWindow &window) {
    window.clear(sf::Color(197,234,250));

    // Position and render the title (centered at the top)
    title.setPosition(window.getSize().x / 2 - title.getGlobalBounds().width / 2, 50);
    window.draw(title);

    // Position and render the instructions (centered below the title)
    instructions.setPosition(window.getSize().x / 2 - instructions.getGlobalBounds().width / 2, 150);
    window.draw(instructions);

    window.display(); 
}

// Handle input and detect any key press
bool IntroductionMenu::handleInput(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();  // Close the window if requested
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            return true;  // Return true if space is pressed
        }
    }
    return false;
}

