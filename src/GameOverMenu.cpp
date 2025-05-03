#include "GameOverMenu.h"
#include <iostream>

// Constructor for Game Over Menu
GameOverMenu::GameOverMenu(int currentScore, int highestScore) : isGameOver(false) {
    if (!menuFont.loadFromFile("assets/fonts/SuperWater.ttf")) {
        cout << "Font not loaded!" << endl;
    }

    // Set up the title
    title.setFont(menuFont);
    title.setString("Game Over");
    title.setCharacterSize(80);
    title.setFillColor(Color(203, 67, 48));
    title.setPosition(300, 200);

    
     // Set up score text
    scoreText.setFont(menuFont);
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(Color::White);
    scoreText.setString("Total Score: " + std::to_string(currentScore));
    scoreText.setPosition(300, 300);

    selectedOption=EXIT;
}

void GameOverMenu::handleInput(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();  // Close the window if requested
        }
    }

    // Check if Enter is pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        selectedOption = EXIT;  // Set selectedOption to EXIT
        std::cout << "Enter pressed: selectedOption set to EXIT" << std::endl;  // Debug output
    }
}

// Render the game over menu
void GameOverMenu:: renderMenu(RenderWindow& window) {  
    window.clear(Color(197,234,250));    
    window.draw(title);
    window.draw(scoreText);          
    window.display();
}


// Return the selected option
GameOverMenu::Option GameOverMenu::getConfirmedOption() const {
    return selectedOption;  // Return the confirmed option stored in the class
}






