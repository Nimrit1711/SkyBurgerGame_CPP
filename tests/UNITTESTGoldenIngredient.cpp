#include <iostream>
#include "GoldenIngredient.h"
#include "Player.h"
#include "Burger.h"

int main() {
    // Create a Burger object
    Burger burger;

    // Create a Player object that takes a pointer to the Burger object
    Player player(&burger);

    // Create a GoldenIngredient object
    GoldenIngredient goldenItem;

    // Test initial behavior
    std::cout << "Golden Ingredient: Testing collision behavior..." << std::endl;

    // Simulate collision
    goldenItem.checkCollision(player, burger);

    // Assuming checkCollision would print some feedback or update the burger

    return 0;
}
