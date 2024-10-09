#include "IntroductionMenu.h"

// Constructor for Introduction Menu
IntroductionMenu::IntroductionMenu() {
    titleFont.loadFromFile("SuperWater.ttf"); //should I include error for when font not loaded?
    menuFont.loadFromFile("arial.ttf");

    // Set up the title
    title.setFont(titleFont);
    title.setString("Sky Burger");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color(255,165,0));

    // Set up the instructions 
    instructions.setFont(menuFont);
    instructions.setString(
        "How to Play:\n"
        "1. Collect freefalling ingredients from the sky to build your burger.\n"
        "   One point per ingredient. Golden ingredients give an extra point.\n\n"
        "2. Each game gives the player three health points. Collect non-edible\n"
        "   ingredients, and lose one health point.\n\n"
        "3. Once all three health points are lost, the game ends.\n\n"
        "Press space to continue"
    );
    instructions.setCharacterSize(24);  // Smaller size for instructions
    instructions.setFillColor(sf::Color(255,140,0));
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

