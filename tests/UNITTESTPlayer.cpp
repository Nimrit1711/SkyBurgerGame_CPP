#include <iostream>
#include "Player.h"
#include "Burger.h"
#include <SFML/Graphics.hpp>

int main() {
    // Create a window and burger
    sf::RenderWindow window(sf::VideoMode(800, 600), "Player Test");
    Burger burger;
    Player player(&burger);

    // Check initial lives
    std::cout << "Initial Lives: " << player.getLives() << std::endl;

    // Simulate losing a life
    player.loseLife();
    std::cout << "Lives after losing one: " << player.getLives() << std::endl;

    // Simulate position update
    player.setPosition(sf::Vector2f(100, 100));
    std::cout << "Player position: (" << player.getPlayerPosition().x << ", " << player.getPlayerPosition().y << ")" << std::endl;

    // Check if player is alive
    std::cout << "Player alive? " << (player.isAlive() ? "Yes" : "No") << std::endl;

    return 0;
}
