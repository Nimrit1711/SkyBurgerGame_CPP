#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "GameMode.h"

// compile code: g++ GameMode.cpp GameModeTester.cpp Player.cpp Burger.cpp FoodItem.cpp Lettuce.cpp Tomato.cpp Onion.cpp Patty.cpp Cheese.cpp Hazards.cpp Bomb.cpp PoisonBottle.cpp GoldenIngredient.cpp BananaPeel.cpp Sock.cpp Game.cpp -lsfml-graphics -lsfml-window -lsfml-system
using namespace sf;
using namespace std;

int main() {
    // Create a Game 
    Game game; 

    // Start the game loop
    game.run(); 

    return 0;
}
