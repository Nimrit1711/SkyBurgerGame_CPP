#include "GameOverMenu.h"
#include <iostream>

// Constructor for Game Over Menu
GameOverMenu::GameOverMenu(int currentScore, int highestScore) : isGameOver(false) {
    if (!menuFont.loadFromFile("arial.ttf")) {
        cout << "Font not loaded!" << endl;
    }

    // Set up the title
    title.setFont(menuFont);
    title.setString("Game Over");
    title.setCharacterSize(50);
    title.setFillColor(Color::White);
    title.setPosition(350, 200);

    
     // Set up score and best score texts
    scoreText.setFont(menuFont);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(Color::White);
    scoreText.setString("Current Score: " + std::to_string(currentScore));
    scoreText.setPosition(350, 300);

    
    bestScoreText.setFont(menuFont);
    bestScoreText.setCharacterSize(30);
    bestScoreText.setFillColor(Color::White);
    bestScoreText.setString("Highest Score: " + std::to_string(highestScore));
    bestScoreText.setPosition(350, 350); 

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
        
    window.clear();

    // Render the title    
    window.draw(title);
    window.draw(scoreText);    
    window.draw(bestScoreText);
    float yOffset = bestScoreText.getPosition().y + bestScoreText.getGlobalBounds().height + 50; // get position
    
    Text menuItem;
    menuItem.setFont(menuFont);
    menuItem.setString("Exit");
    menuItem.setCharacterSize(40);
    menuItem.setFillColor(Color::White);
    
    // Set position of the menu items
    menuItem.setPosition(window.getSize().x / 2 - menuItem.getGlobalBounds().width / 2, bestScoreText.getPosition().y + 100);
    window.draw(menuItem);        
    window.display();
}


// Return the selected option
GameOverMenu::Option GameOverMenu::getConfirmedOption() const {
    return selectedOption;  // Return the confirmed option stored in the class
}




